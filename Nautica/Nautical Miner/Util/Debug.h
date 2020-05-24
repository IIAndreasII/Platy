#ifndef DEBUG_H
#define DEBUG_H


#include <vector>

class Debug
{
public:
	~Debug();

	static void Init();
	static void FinishSession();
	static void Log(const std::string entry, const bool success = true);

private:
	Debug();

	static std::vector<std::string> myLogEntries;
	static std::string GetTime();

};

#endif