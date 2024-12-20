#include "pch.h"
#include"../Executor/Executor.h"
#include"../Executor/Executor.cpp"



bool operator==(const Direction& d1, const Direction& d2) {
	return d1.Head == d2.Head;
}



bool operator==(const Point& p1, const Point& p2) {
	return p1.x == p2.x && p1.y == p2.y;
}


bool operator==(const Pose& p1, const Pose& p2) {
	return (p1.point == p2.point&&p1.direction==p2.direction);
}




TEST(ExecutorTest,MOVECOMMEND) {
	Exceutor exceutor{ {{1,1},{'N'}} };
	exceutor.CommendCarry("M");
	Pose pose{ {1,2},{'N'} };
	EXPECT_EQ(pose, exceutor.GetPose());
}


TEST(ExecutorTest, TURNLEFTCOMMEND) {
	Exceutor exceutor{ {{1,1},{'N'}} };
	exceutor.CommendCarry("L");
	Pose pose{ {1,1},{'W'} };
	EXPECT_EQ(pose, exceutor.GetPose());
}

TEST(ExecutorTest, TURNRIGHTCOMMEND) {
	Exceutor exceutor{ {{1,1},{'N'}} };
	exceutor.CommendCarry("R");
	Pose pose{ {1,1},{'E'} };
	EXPECT_EQ(pose, exceutor.GetPose());
}

TEST(ExecutorTest, FASTCOMMEND) {
	Exceutor exceutor{ {{1,1},{'N'}} };
	exceutor.CommendCarry("F");
	exceutor.CommendCarry("M");
	Pose pose{ {1,3},{'N'} };
	EXPECT_EQ(pose, exceutor.GetPose());
	exceutor.CommendCarry("F");
	exceutor.CommendCarry("M");
	Pose pose2{ {1,4},{'N'} };
	EXPECT_EQ(pose2, exceutor.GetPose());
}

TEST(ExecutorTest, BACKCOMMEND) {
	Exceutor exceutor{ {{1,1},{'N'}} };
	exceutor.CommendCarry("B");
	exceutor.CommendCarry("M");
	Pose pose{ {1,0},{'N'} };
	EXPECT_EQ(pose, exceutor.GetPose());
	exceutor.CommendCarry("B");
	exceutor.CommendCarry("M");
	Pose pose2{ {1,1},{'N'} };
	EXPECT_EQ(pose2, exceutor.GetPose());
}


TEST(ExecutorTest, TURNARROUNDCOMMEND) {
	Exceutor exceutor{ {{1,1},{'N'}} };
	exceutor.CommendCarry("TR");
	Pose pose{ {0,1},{'S'} };
	EXPECT_EQ(pose, exceutor.GetPose());
	exceutor.CommendCarry("F");
	exceutor.CommendCarry("TR");
	Pose pose2{ {1,0},{'N'} };
	EXPECT_EQ(pose2, exceutor.GetPose());
}

TEST(SportyCarTest, MOVECOMMEND) {
	SportyCar exceutor{ {{1,1},{'N'}} };
	exceutor.CommendCarry("M");
	Pose pose{ {1,3},{'N'} };
	EXPECT_EQ(pose, exceutor.GetPose());

}

TEST(SportyCarTest, TURNLEFTCOMMEND) {
	SportyCar exceutor{ {{1,1},{'N'}} };
	exceutor.CommendCarry("L");
	Pose pose{ {0,1},{'W'} };
	EXPECT_EQ(pose, exceutor.GetPose());
}

TEST(SportyCarTest, TURNRIGHTCOMMEND) {
	SportyCar exceutor{ {{1,1},{'N'}} };
	exceutor.CommendCarry("R");
	Pose pose{ {2,1},{'E'} };
	EXPECT_EQ(pose, exceutor.GetPose());
}

TEST(SportyCarTest,FASTCOMMEND) {
	SportyCar exceutor{ {{1,1},{'N'}} };
	exceutor.CommendCarry("F");
	exceutor.CommendCarry("M");
	Pose pose{ {1,5},{'N'} };
	EXPECT_EQ(pose, exceutor.GetPose());
}


TEST(SportyCarTest, BACKCOMMEND) {
	SportyCar exceutor{ {{1,1},{'N'}} };
	exceutor.CommendCarry("B");
	exceutor.CommendCarry("M");
	Pose pose{ {1,-1},{'N'} };
	EXPECT_EQ(pose, exceutor.GetPose());
}


TEST(BusTest, MOVECOMMEND) {
	Bus exceutor{ {{1,1},{'N'}} };
	exceutor.CommendCarry("M");
	Pose pose{ {1,2},{'N'} };
	EXPECT_EQ(pose, exceutor.GetPose());
}

TEST(BusTest, TURNLEFTCOMMEND) {
	Bus exceutor{ {{1,1},{'N'}} };
	exceutor.CommendCarry("L");
	Pose pose{ {1,2},{'W'} };
	EXPECT_EQ(pose, exceutor.GetPose());
}

TEST(BusTest, TURNRIGHTCOMMEND) {
	Bus exceutor{ {{1,1},{'N'}} };
	exceutor.CommendCarry("R");
	Pose pose{ {1,2},{'E'} };
	EXPECT_EQ(pose, exceutor.GetPose());
}


TEST(BusTest,FASTCOMMEND) {
	Bus exceutor{ {{1,1},{'N'}} };
	exceutor.CommendCarry("F");
	exceutor.CommendCarry("M");
	Pose pose{ {1,3},{'N'} };
	EXPECT_EQ(pose, exceutor.GetPose());
}


TEST(BusTest, BACKCOMMEND) {
	Bus exceutor{ {{1,1},{'N'}} };
	exceutor.CommendCarry("B");
	exceutor.CommendCarry("M");
	Pose pose{ {1,0},{'N'} };
	EXPECT_EQ(pose, exceutor.GetPose());
}





int main(int argc, char** argv) {
	::testing::InitGoogleTest(&argc, argv);
	int result = RUN_ALL_TESTS();
}