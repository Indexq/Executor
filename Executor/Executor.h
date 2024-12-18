#pragma once
#include<map>
#include<string>
class Point {
public:
	Point operator +(const Point& point) const;
	Point operator =(const Point& point);
	Point(int x,int y);
	Point();
	void Show();
private:
	int x;
	int y;

};

class Direction {
public:
	Direction(int Head, char heading) ;
	Direction();
	Direction(char heading);
	
	char direction[4] = {'N','E','S','W'};

	
	void TurnLeft();
	void TurnRight();

	int GetHead();
	char Getheading();

	void Show();
private:
	int Head;
	char heading;
};


class Pose{
public:
	Pose(Point point, Direction direction);
	Pose();
	Point points[4] = { {0,1},{1,0},{0,-1},{-1,0} };

	void Move();
	void TurnLeft();
	void TurnRight();
	void Back();
	void Show();
	void ShowPoint();
	void ShowDirection();
private:
	Point point;
	Direction direction;
};



class Exceutor {
public:
	Exceutor(Pose pose);
	Exceutor();
	void FastCommend();
	void BackCommend();
	void ShowPose();
	void Move();
	void TurnLeft();
	void TurnRight();
	void CommendCarry(std::string str);
private:
	void CmdGroupSet();
	void MoveCommend();
	void TurnLeftCommend();
	void TurnRightCommend();
	void TurnAroundCommend();
	std::map<std::string, void(Exceutor::*)()> CmdGroup;


	
protected:
	Pose pose;
	bool isFast;
	bool isBack;
};


class SportyCar :Exceutor {
public:
	SportyCar(Pose pose);
	SportyCar();
	void CommendCarry(std::string str);
private:
	void CmdGroupSet();
	void MoveCommend();
	void TurnLeftCommend();
	void TurnRightCommend();
	std::map<std::string, void(SportyCar::*)()> CmdGroup;
};

class Bus :Exceutor {
public:
	Bus(Pose pose);
	Bus();
	void CommendCarry(std::string str);
	void ShowPose();
	void GetBack();
private:
	void CmdGroupSet();
	void MoveCommend();
	void TurnLeftCommend();
	void TurnRightCommend();
	std::map<std::string, void(Bus::*)()> CmdGroup;
	Pose back;
};


