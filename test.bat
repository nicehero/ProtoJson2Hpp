cd proto
python ProtoJson2Hpp.py
cd ..
g++ -std=c++11 test.cpp proto/cmd.cpp -o test
call test.exe

pause