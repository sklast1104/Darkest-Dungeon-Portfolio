# Darkest-Dungeon-Portfolio

## Youtube
[Youtube Link](https://www.youtube.com/watch?v=21wzPrDZCqk)

## 개요

### 선정 동기

평소에 턴제 게임(문명, 다키스트 던전, 슬레이 더 스파이어, 드래곤 퀘스트) 등등을 즐겨하고 좋아해서 첫 프로젝트는 턴제 게임을 만들면 좋겠다고 생각해서 프로젝트를 시작하였습니다

### 프로젝트 기간

3.30 ~ 4.14 (약 16일)

### 사용 기술 스택

C++, Winapi, DSound

## 목표

### 문제 정의

턴제 게임이다 보니 상호작용은 UI 위주로 일어나기 때문에 **UI를 얼마나 효과적으로 빠르게 구현할 수 있는지**가 중점이였던것 같습니다 그 외에는 턴제 게임의 규칙을 만들기 위해 **상태머신을
잘 설계**하는것이 중요하였습니다 전반적인 작업 내용은 UI가 6~7할 상태머신 설계가 2할 나머지 1할정도의 작업이 되었습니다

### 문제점

C++은 C#의 이벤트나 Javascript의 이벤트 핸들러와 같은 기능들을 통해 이벤트 프로그래밍을 적극적으로 지원하는 언어는 아니였어서 UI를 동작시킬떄 어려움을 겪었습니다 처음엔 버튼 하나하나
마다 직접 클래스를 만들어서 작업을 처리하도록 작성했었는데 이렇게 만들다보니 사실상 이벤트 처리 빼고는 나머지는 다 중복되는 코드였기 때문에 코드의 크기가 쓸데없이 커진다는 문제점이
있었습니다

### 해결 방법

    void DivUI::update()
    {
	UI::update();

	// 렌더좌표인데 카메라 정방향 or 카메라 영향을 받지 않는 UI면 상관없음
	Vec2 mousePos = MOUSE_POS;

	Vec2 myScale = GetScale();
	Vec2 finalPos = GetFinalPos();

	// 마우스가 UI안에 있는지
	bool isMouseOver = (finalPos.x <= mousePos.x && mousePos.x <= finalPos.x + myScale.x
		&& finalPos.y <= mousePos.y && mousePos.y <= finalPos.y + myScale.y);

	// UI안에 있는데 이전에 들어왔던적이 없으면
	if (isMouseOver && !wasMouseOver) {

		wasMouseOver = true;
		// 마우스 엔터 이벤트 호출!
		if (nullptr != onMouseEnter) {
			onMouseEnter->Execute();
		}
	}

	// UI 안에 없는데 이전에 들어왔었으면
	if (!isMouseOver && wasMouseOver) {
		wasMouseOver = false;
		// 마우스 익시트 이벤트 호출!
		if (nullptr != onMouseExit) {
			onMouseExit->Execute();
		}
	}

	// 그냥 떠있으면
	if (isMouseOver) {
		// 마우스 오버 이벤트 호출!
		if (nullptr != onMouseOver) {
			onMouseOver->Execute();
		}
	}
	else {
		// 마우스 낫 오버 이벤트 호출!
		if (nullptr != onMouseOut) {
			onMouseOut->Execute();
		}
	}
    }
    
  해결방법을 고민하던중 디자인 패턴 책을 통해 커맨드 패턴을 알았고 위와 같이 커맨드 패턴을 통해 이벤트를 처리할수 있도록 만들었습니다 
  
  onMouseEnter는 Command 패턴의 객체 포인터이고 
  DivUI를 InitMouseEnter(new CCommand) 등으로 커맨드 객체를 초기화 해 다른 언어에서 지원하는 일급객체를 개념을 흉내내었고 UI를 쉽게 구현할 수 있게 된 것 같습니다
  

  
  
  
