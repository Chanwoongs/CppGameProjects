#include "GameLevel.h"

#include "Engine/Engine.h"
#include "Actor/Wall.h"
#include "Actor/Ground.h"
#include "Actor/Box.h"
#include "Actor/Target.h"
#include "Actor/Player.h"

GameLevel::GameLevel()
{
    // 커서 감추기
    Engine::Get().SetCursorType(CursorType::NoCursor);

    // 맵 파일 불러와 업로드
    // 파일 읽기
    FILE* file = nullptr;
    fopen_s(&file, "../Assets/Maps/Stage1.txt", "rb");

    // 파일 처리
    if (file == nullptr)
    {
        std::cout << "맵 파일 열기 실패\n";
        __debugbreak();
        return;
    }

    // 파일 읽기
    // 끝 위치로 이동
    fseek(file, 0, SEEK_END);

    // 이동한 위치의 FP 가져오기
    size_t readSize = ftell(file);

    // FP 원위치
    //fseek(file, 0, SEEK_SET); // set, cur, end
    rewind(file);

    // 파일 읽어서 버퍼에 담기
    char* buffer = new char[readSize + 1]; // 마지막 널 문자
    size_t bytesRead = fread(buffer, 1, readSize, file);

    if (readSize != bytesRead)
    {
        std::cout << "읽어온 크기가 다름\n";
        __debugbreak();
        return;
    }

    buffer[readSize] = '\0';

    // 파일 읽을 때 사용할 인덱스
    int index = 0;

    // 좌표 계산을 위한 변수 선언
    int xPosition = 0;
    int yPosition = 0;

    // 해석 (파싱-Parcing)
    while (index < (int)bytesRead)
    {
        char mapChar = buffer[index++];

        if (mapChar == '\n')
        {
            ++yPosition;
            xPosition = 0;
            continue;
        }

        if (mapChar == '1')
        {
            Wall* wall = new Wall(Vector2(xPosition, yPosition));
            actors.PushBack(wall);
            map.PushBack(wall);
        }
        else if (mapChar == '.')
        {
            Ground* ground = new Ground(Vector2(xPosition, yPosition));
            actors.PushBack(ground);
            map.PushBack(ground);
        }
        else if (mapChar == 'b')
        {
            // 박스는 움직일 수 있기 때문에, Ground도 추가
            Ground* ground = new Ground(Vector2(xPosition, yPosition));
            actors.PushBack(ground);
            map.PushBack(ground);

            Box* box = new Box(Vector2(xPosition, yPosition));
            actors.PushBack(box);
            boxes.PushBack(box);
        }
        else if (mapChar == 't')
        {
            Target* target = new Target(Vector2(xPosition, yPosition));
            actors.PushBack(target);
            targets.PushBack(target);
        }
        else if (mapChar == 'p')
        {
            Ground* ground = new Ground(Vector2(xPosition, yPosition));
            actors.PushBack(new Ground(Vector2(xPosition, yPosition)));
            map.PushBack(ground);

            player = new Player(Vector2(xPosition, yPosition));
            actors.PushBack(player);
        }
        ++xPosition;
    }
    
    delete[] buffer;

    fclose(file);
}

void GameLevel::Draw()
{
    // 맵 그리기
    for (auto& actor : map)
    {
        actor->Draw();
    }
    
    // 타겟 그리기
    for (auto& actor : targets)
    {
        actor->Draw();
    }

    // 박스 그리기
    for (auto& actor : boxes)
    {
        actor->Draw();
    }

    // 플레이어 그리기
    player->Draw();
}
