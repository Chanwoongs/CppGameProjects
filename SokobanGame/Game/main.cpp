#include <iostream>

int main()
{
    // 파일 읽기
    FILE* file = nullptr;
    fopen_s(&file, "../Assets/Maps/Map.txt", "rb");

    // 파일 처리
    if (file == nullptr)
    {
        std::cout << "맵 파일 열기 실패\n";
        return -1;
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
        return -1;
    }

    buffer[readSize] = '\0';

    std::cout << buffer << '\n';

    delete[] buffer;
}