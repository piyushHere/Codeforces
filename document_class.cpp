#include<bits/stdc++.h>
using namespace std;

class document {
public:
	string question = "document";
	int time = 0;
	virtual void parse() = 0;
};

class MCQ : public document {
public:
	string options = "mcq";
	string answer = "0";
	void parse() {
		cout << question << time  << options << answer;
	}
};

class shortAnswer : public document {
public:
	string tags;
	void parse() {
		cout << question << time  << tags;
	}
};


int main() {
	// base class
	document *doc;
	MCQ mcqDOC;
	shortAnswer shortAnswerDOC;
	//doc.parse();
	//mcqDOC.parse();
	doc = &mcqDOC;
	doc->parse();
}