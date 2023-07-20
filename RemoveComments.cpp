#include <bits/stdc++.h>
#include <windows.h>
using namespace std;

int main() {
	bool gs = 0;//1为修改格式，0为不修改
	int cs = 0;
	bool lz = 0;
	bool zs = 1;//1为删除注释，0为不删除
	string in, ans;
	char y = '"';
	cout << "┌-----状态栏----┐\n|修改格式：";
	if (gs) {
		cout << "TURE |\n";
	} else {
		cout << "FALSE|\n";
	}
	cout << "|删除注释：";
	if (zs) {
		cout << "TURE |\n";
	} else {
		cout << "FALSE|\n";
	}
	cout << "└---------------┘\n";
	cout << "温馨提示：包含中文引号(“)会识别为英文引号(" << y <<
	     ")，请自行调整或复制代码后编译查看错误并修改\n请复制代码,输入end结束:\n";
	while (1) {
		cin.clear();
		getline(cin, in);
		if (in == "end") {
			break;
		}
		int d = 0;
		for (int i = 0; i < in.size(); i++) {
			if (in[i] == '}') {
				cs--;
				d++;
			}
		}
		if (gs == 1) {
			for (int i = 1; i <= cs; i++) {
				ans += "    ";
			}
		}
		cs += d;
		for (int i = 0; i < in.size(); i++) {
			if (in[i] == '{') {
				if (gs == 1) {
					cs++;
				} else {
					gs = 1;
					cs++;
				}
			}
			if (in[i] == '}') {
				cs--;
				if (cs <= 0) {
					cs = 0;
					gs = 0;
				}
			}
			if (zs == 1) {
				if (lz == 1) {
					continue;
				}
				if (i != in.size() - 1 && in[i] == '/' && in[i + 1] == '/') {
					break;
				} else if (i != in.size() - 1 && in[i] == '/' && in[i + 1] == '*') {
					lz = 1;
				} else if (i != in.size() - 1 && in[i] == '*' && in[i + 1] == '/') {
					lz = 0;
				} else {
					ans += in[i];
				}
			} else {
				ans += in[i];
			}

		}
		ans += "\n";
	}
	cout << "-------------------------正在修改ing...--------------------\n";
	Sleep(3000);
	cout << "-------------------------以下是修改结果--------------------\n";
	for (int i = 0; i < ans.length(); i++) {
		if (ans[i] + ans[i + 1] != '\\n')
			cout << ans[i];
		else {
			if (!(ans[i - 1] + ans[i] + ans[i + 1] + ans[i + 1] == '\'\\n\'')
			        && !(ans[i - 1] + ans[i] + ans[i + 1] + ans[i + 1] == '"\\n"')) {
				cout << endl;
				i++;
			}
		}
		Sleep(10);
	}
	cout << endl;
	cout << "由lichenzhen和henglizuo提供，lichenzhen提供第一版，henglizuo修复了其中的bug。\n注意！此代码不准用于抄题解！注意！如果用了本代码去掉题解的注释，后果自负，作者们不负任何责任！";
	return 0;
}
