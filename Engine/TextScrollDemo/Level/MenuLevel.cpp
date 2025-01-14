#include "MenuLevel.h"
#include "Game/Game.h"

MenuLevel::MenuLevel()
{
    // 메뉴 초기화
    items.emplace_back(new MenuItem("Resume Game", []() { Game::Get().ToggleMenu(); }));
    items.emplace_back(new MenuItem("Quit Game", []() { Game::Get().QuitGame(); }));

    // 메뉴 개수 저장
    itemCount = (int)items.size();
}

MenuLevel::~MenuLevel()
{
    for (MenuItem* item : items)
    {
        delete item;
    }
    items.clear();
}

void MenuLevel::Update(float deltaTime)
{
    Super::Update(deltaTime);

    // ESC키가 눌리면 메뉴 토글
    if (Game::Get().GetKeyDown(VK_ESCAPE))
    {
        Game::Get().ToggleMenu();
    }

    // 위아래 방향키
    if (Game::Get().GetKeyDown(VK_UP))
    {
        // 인덱스 변환
        currentSelectedIndex = (currentSelectedIndex - 1 + itemCount) % itemCount;
    }
    if (Game::Get().GetKeyDown(VK_DOWN))
    {
        currentSelectedIndex = (currentSelectedIndex + 1) % itemCount;
    }

    // 엔터키
    if (Game::Get().GetKeyDown(VK_RETURN))
    {
        items[currentSelectedIndex]->onSelected();
    }
}

void MenuLevel::Draw()
{
    Super::Draw();

    // 메뉴 제목 출력
    static HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(handle, unselectedColor);
    std::cout << "Text Scroll Demo Menu\n\n";

    // 루프 순외하면서 메뉴 텍스트 출력
    for (int i = 0; i < itemCount; i++)
    {
        SetConsoleTextAttribute(
            handle,
            i == currentSelectedIndex ? selectedColor : unselectedColor
        );

        // 출력
        std::cout << items[i]->text << '\n';
    }
}
