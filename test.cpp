
#include "Message.h"
#include <stdio.h>
#include "proto/TestProto2.hpp"

int main()
{
	Proto::TestType3 xxx;
	Proto::TestType2 xxx2;
	xxx2.test.myUi64 = 99999;
	xxx2.myString = "hello world";
	xxx.operNum = 100;
	xxx.storeNum = 200;
	xxx.myNum = 666;
	xxx.test.push_back(xxx2);
	xxx.test.push_back(xxx2);
	xxx.test.push_back(std::move(xxx2));
	
	//Serialize
	nicehero::Message msg;
	xxx.toMsg(msg);
	
	//Unserialize
	Proto::TestType3 yyy;
	msg >> yyy;
	
	printf("%s:%d\n",yyy.test[2].myString.c_str(),int(yyy.myNum));
	printf("operNum:%d\n",int(yyy.operNum.impl));
	printf("storeNum:%d\n",int(yyy.storeNum.impl));
	
	return 0;
}

