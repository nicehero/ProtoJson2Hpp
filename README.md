## ProtoJson2Hpp
  A lightweight json type proto what can convert to c++11 code for serialize

  how to use

  edit some json file make some struct like
```javascript
    {
            "typeName" : "TestType2",//struct name
            "isMsg" : false,//if true as the struct is a message, the type TestType2 will gen a TestType2ID (typeName + ID)
            "fields" : [
                    {
                            "name" :"myString",//field name
                            "type" : "string",//field type
                            "default" : "aaa"//set a default value
                    }
                    ,{
                            "name" :"test",
                            "type" : "TestType"//can use user struct
                     }
                    ,{
                            "name" :"testList",
                            "type" : "<ui32"// '<' is a list warp: this type is std::vector<ui32>,
                    }
                    ,{
                            "name" :"testList",
                            "type" : "<<string"//this type is std::vector<std::vector<string> >
                    }
                    ,{
                            "name" :"myInt",
                            "type" : "ui32",
							"default" : 1
                    }
                    ,{
                            "name" :"testCondition",
                            "type" : "ui32",
							"default" : 1,
							"condition" : "myInt == 0"//only this condition is true then serialize the field
                    }
            ]
    }

```
  use ProtoJson2Hpp.py to make hpp code file and a cmd.cpp for msgIDs file
  
  one json file make a one hpp file,and it will auto gen depends relation(#include)
  
  support base type: i8 i16 i32 i64 ui8 ui16 ui32 ui64 string binary OperUInt StoreUInt

  cmd_fix.json is your customer id value
  


=========================================================================

  一个轻量级json协议转成c++11代码的序列化库
  
  如何使用:
  
  编辑一些json文件，在里面写一些结构体，例：

```javascript
    {
            "typeName" : "TestType2",//结构名
            "isMsg" : false,//如果为true，代表这个结构体可以作为一条消息，那会为你生成一个关于这个结构的消息ID:TestType2ID(结构名 + ID)
            "fields" : [
                    {
                            "name" :"myString",//字段名
                            "type" : "string",//字段类型
                            "default" : "aaa"//字段默认值
                    }
                    ,{
                            "name" :"test",
                            "type" : "TestType"//可以使用其他结构作为类型
                     }
                    ,{
                            "name" :"testList",
                            "type" : "<ui32"// '<' 符号代表数组的抽象，此字段代表的类型为 std::vector<ui32>,
                    }
                    ,{
                            "name" :"testList",
                            "type" : "<<string"//此字段代表的类型为 std::vector<std::vector<std::string> >
                    }
                    ,{
                            "name" :"myInt",
                            "type" : "ui32",
							"default" : 1
                    }
                    ,{
                            "name" :"testCondition",
                            "type" : "ui32",
							"default" : 1,
							"condition" : "myInt == 0"//当字段拥有condition时，仅当其中条件为真时才会序列化此字段
                    }
            ]
    }

```

  使用ProtoJson2Hpp.py文件来生成hpp代码和cmd.cpp代码,cmd.cpp里将会保存消息的ID
  
  一个json文件将生成一个hpp文件,脚本将会自动为你组织好依赖关系(#include)
  
  支持的基础类型: i8 i16 i32 i64 ui8 ui16 ui32 ui64 string binary OperUInt StoreUInt

  可以编辑cmd_fix.json文件，来制定某些你需要特定的消息ID

