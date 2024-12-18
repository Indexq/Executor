#include "Executor.h"
#include <map>
#include <iostream>
Direction::Direction(int Head, char heading)
{
	this->Head = Head;
	this->heading = heading;
}

Direction::Direction()
{
	this->Head = 0;
	this->heading = 'N';
}

Direction::Direction(char heading)
{
	this->heading = heading;
	for (int i = 0; i < 4; i++) {
		if (direction[i] == heading) {
			this->Head = i;
			break;
		}
	}
}



void Direction::TurnLeft()
{
	Head = (Head + 3) % 4;
	heading = direction[Head];
}

void Direction::TurnRight()
{
	Head = (Head + 1) % 4;
	heading = direction[Head];
}

int Direction::GetHead()
{
	return Head;
}

char Direction::Getheading()
{
	return heading;
}

void Direction::Show()
{
	std::cout << heading;
}

Point Point::operator+(const Point& point) const
{
	return Point(x+point.x,y+point.y);
}

Point Point::operator=(const Point& point)
{	
	this->x = point.x;
	this->y = point.y;
	return *this;
}

Point::Point(int x, int y)
{
	this->x = x;
	this->y = y;
}

Point::Point()
{
	this->x = 0;
	this->y = 0;
}

void Point::Show()
{
	std::cout << x << " " << y<<" ";
}



Pose::Pose(Point point, Direction direction)
{
	this->point = point;
	this->direction = direction;
}

Pose::Pose()
{
	
}

void Pose::Move()
{
	this->point = this->point + points[direction.GetHead()];
}

void Pose::TurnLeft()
{
	direction.TurnLeft();
}

void Pose::TurnRight()
{
	direction.TurnRight();
}

void Pose::Back()
{
	this->point = this->point + points[(direction.GetHead()+2)%4];
}

void Pose::Show()
{
	point.Show();
	std::cout << " ";
	direction.Show();
}

void Pose::ShowPoint()
{
	point.Show();
}

void Pose::ShowDirection()
{
	direction.Show();
}



Exceutor::Exceutor(Pose pose)
{
	this->pose = pose;
	isFast = 0;
	isBack = 0;
	CmdGroupSet();
}

Exceutor::Exceutor()
{
	isFast = 0;
	isBack = 0;
	CmdGroupSet();
}

void Exceutor::FastCommend()
{
	if (isFast == 0)
		isFast = 1;
	else
		isFast = 0;
}

void Exceutor::BackCommend()
{
	if (isBack == 0)
		isBack = 1;
	else
		isBack = 0;
}

void Exceutor::ShowPose()
{
	pose.Show();
}

void Exceutor::Move()
{
	if (isBack == 0)
		pose.Move();
	else
		pose.Back();
}

void Exceutor::TurnLeft()
{
	if (isBack == 0)
		pose.TurnLeft();
	else
		pose.TurnRight();
}

void Exceutor::TurnRight()
{
	if (isBack == 0)
		pose.TurnRight();
	else
		pose.TurnLeft();
}

void Exceutor::CommendCarry(std::string str)
{
	if (CmdGroup.count(str) == 1)
		(this->*CmdGroup[str])();
}

void Exceutor::CmdGroupSet()
{	
	
	CmdGroup.insert(std::pair<std::string, void(Exceutor::*)()>("M", &Exceutor::MoveCommend));
	CmdGroup.insert(std::pair<std::string, void(Exceutor::*)()>("L", &Exceutor::TurnLeftCommend));
	CmdGroup.insert(std::pair<std::string, void(Exceutor::*)()>("R", &Exceutor::TurnRightCommend));
	CmdGroup.insert(std::pair<std::string, void(Exceutor::*)()>("TR", &Exceutor::TurnAroundCommend));
	CmdGroup.insert(std::pair<std::string, void(Exceutor::*)()>("F", &Exceutor::FastCommend));
	CmdGroup.insert(std::pair<std::string, void(Exceutor::*)()>("B", &Exceutor::BackCommend));
	CmdGroup.insert(std::pair<std::string, void(Exceutor::*)()>("S", &Exceutor::ShowPose));

	
}

void Exceutor::MoveCommend()
{
	Move();
	if (isFast == 1)
		Move();
}

void Exceutor::TurnLeftCommend()
{
	if (isFast == 1)
		Move();
	TurnLeft();

}

void Exceutor::TurnRightCommend()
{
	if (isFast == 1)
		Move();
	TurnRight();
}

void Exceutor::TurnAroundCommend()
{
	if (isFast == 1)
		Move();
	TurnLeft();
	Move();
	TurnLeft();
}

SportyCar::SportyCar(Pose pose)
{
	this->pose = pose;
	isFast = 0;
	isBack = 0;
	CmdGroupSet();
}

SportyCar::SportyCar()
{
	isFast = 0;
	isBack = 0;
	CmdGroupSet();
}

void SportyCar::CommendCarry(std::string str)
{
	if (CmdGroup.count(str) == 1)
		(this->*CmdGroup[str])();
}

void SportyCar::CmdGroupSet()
{
	CmdGroup.insert(std::pair<std::string, void(SportyCar::*)()>("M", &SportyCar::MoveCommend));
	CmdGroup.insert(std::pair<std::string, void(SportyCar::*)()>("L", &SportyCar::TurnLeftCommend));
	CmdGroup.insert(std::pair<std::string, void(SportyCar::*)()>("R", &SportyCar::TurnRightCommend));
	CmdGroup.insert(std::pair<std::string, void(SportyCar::*)()>("F", &SportyCar::FastCommend));
	CmdGroup.insert(std::pair<std::string, void(SportyCar::*)()>("B", &SportyCar::BackCommend));
	CmdGroup.insert(std::pair<std::string, void(SportyCar::*)()>("S", &SportyCar::ShowPose));
}


void SportyCar::MoveCommend()
{
	Move();
	Move();
	if (isFast == 1) {
		Move();
		Move();
	}
}

void SportyCar::TurnLeftCommend()
{
	if (isFast == 1)
		Move();
	TurnLeft();
	Move();
}

void SportyCar::TurnRightCommend()
{
	if (isFast == 1)
		Move();
	TurnRight();
	Move();
}

Bus::Bus(Pose pose)
{
	this->pose = pose;
	isFast = 0;
	isBack = 0;
	CmdGroupSet();
}

Bus::Bus()
{
	isFast = 0;
	isBack = 0;
	CmdGroupSet();
}

void Bus::CommendCarry(std::string str)
{
	if (CmdGroup.count(str) == 1)
		(this->*CmdGroup[str])();
}

void Bus::ShowPose()
{	
	GetBack();
	std::cout << "front:";
	pose.ShowPoint();
	std::cout << " back:";
	back.ShowPoint();
	std::cout << " ";
	pose.ShowDirection();
}

void Bus::GetBack()
{
	Pose temp = pose;
	temp.Back();
	back = temp;
}

void Bus::CmdGroupSet()
{
	CmdGroup.insert(std::pair<std::string, void(Bus::*)()>("M", &Bus::MoveCommend));
	CmdGroup.insert(std::pair<std::string, void(Bus::*)()>("L", &Bus::TurnLeftCommend));
	CmdGroup.insert(std::pair<std::string, void(Bus::*)()>("R", &Bus::TurnRightCommend));
	CmdGroup.insert(std::pair<std::string, void(Bus::*)()>("F", &Bus::FastCommend));
	CmdGroup.insert(std::pair<std::string, void(Bus::*)()>("B", &Bus::BackCommend));
	CmdGroup.insert(std::pair<std::string, void(Bus::*)()>("S", &Bus::ShowPose));
}

void Bus::MoveCommend()
{
	if (isFast == 1)
		Move();
	Move();
}

void Bus::TurnLeftCommend()
{
	if (isFast == 1)
		Move();
	Move();
	TurnLeft();
}

void Bus::TurnRightCommend()
{
	if (isFast == 1)
		Move();
	Move();
	TurnRight();
}
