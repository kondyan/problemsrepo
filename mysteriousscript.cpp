#include <bits/stdc++.h>
using namespace std;
#define int int64_t

string ten_to_nine (int num)
{
	deque<int> res;
	while (num != 0)
	{
		int rest = num % 9;
		res.push_front(rest);
		num /= 9;
	}
	string s;
	for (auto num : res)
	{
		s += to_string(num);
	}
	return s;
}

int nine_to_ten (int num)
{
	int multiplier = 1;
	int res = 0;
	for (int i = to_string(num).size() - 1; i >= 0; i--)
	{
		char curr_num = to_string(num)[i];
		res += (curr_num - '0') * multiplier;
		multiplier *= 9;
	}
	return res;
}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	string s1, s2; cin >> s1 >> s2;

	unordered_map<string, char > number_mapping; // base 9
	unordered_map<int, string >reverse_mapping;
	number_mapping["la"] = '0';
	number_mapping["le"] = '1';
	number_mapping["lon"] = '2';
	number_mapping["sha"] = '3';
	number_mapping["she"] = '4';
	number_mapping["shon"] = '5';
	number_mapping["ta"] = '6';
	number_mapping["te"] = '7';
	number_mapping["ton"] = '8';
	reverse_mapping[0] = "la";
	reverse_mapping[1] = "le";
	reverse_mapping[2] = "lon";
	reverse_mapping[3] = "sha";
	reverse_mapping[4] = "she";
	reverse_mapping[5] = "shon";
	reverse_mapping[6] = "ta";
	reverse_mapping[7] = "te";
	reverse_mapping[8] = "ton";

	int size1 = s1.size();
	int size2 = s2.size();

	string curr_s1;
	string curr_num1 ;
	for (int i = 0; i < size1; i++)
	{
		char curr_char = s1[i];
		curr_s1+=curr_char;
		if (number_mapping.contains(curr_s1))
		{
			curr_num1+= number_mapping[curr_s1];
			curr_s1 = "";
		}
	}

	string curr_s2;
	string curr_num2;
	for (int i = 0 ; i < size2; i ++)
	{
		char curr_char = s2[i];
		curr_s2 += curr_char;
		if (number_mapping.contains(curr_s2))
		{
			curr_num2+= number_mapping[curr_s2];
			curr_s2 = "";
		}
	}

	int a = nine_to_ten(stoull(curr_num1));
	int b = nine_to_ten(stoull(curr_num2));


	string res = ten_to_nine(a + b);

	for (auto n : res)
	{
		cout <<  reverse_mapping[n - '0'];
	}

	cout << 's';
	return 0;


}