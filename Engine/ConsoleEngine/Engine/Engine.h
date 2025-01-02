#pragma once

// 엔진 클래스
class Engine
{
public:
	Engine();
	virtual ~Engine();

	// 엔진 실행 함수
	void Run();

protected:
	void ProcessInput();				// 입력
	void Update(float deltaTime);		// Tick
	void Draw();						// Render

private:

	// 종료할 때 설정할 변수
	bool quit;
};