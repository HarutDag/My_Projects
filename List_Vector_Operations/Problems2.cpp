#include <iostream>
#include <vector>

struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

int singleNumber(std::vector<int>&);
std::vector<int> singleNumbers(std::vector<int>&);
bool isNumber(std::string);
ListNode* mergeKLists(std::vector<ListNode*>&);
ListNode* deleteDuplicates(ListNode*);
bool isPalindrome(ListNode*);
ListNode* removeElements(ListNode*, int);
ListNode* reverseList(ListNode*);
ListNode* getIntersectionNode(ListNode*, ListNode*);
void deleteNode(ListNode*);
bool hasCycle(ListNode*);
std::vector<int> productExceptSelf(std::vector<int>&);

int main()
{
	std::cout << "1.\n\n";

	std::vector <int> _1arr{ 2, 2, 3, 2 };
	std::vector <int> _1arr2{ 0,1,0,1,0,1,99 };

	std::cout << singleNumber(_1arr) << '\n' << singleNumber(_1arr2) << '\n';

	std::cout << "\n2.\n\n";

	std::vector <int> _2arr{ 1,2,1,3,2,5 };
	std::vector <int> _2arr2{ -1,0 };
	std::vector <int> _2arr3{ 0, 1 };

	std::vector <int> _2tmp = singleNumbers(_2arr);
	std::vector <int> _2tmp2 = singleNumbers(_2arr2);
	std::vector <int> _2tmp3 = singleNumbers(_2arr3);

	for (auto i : _2tmp)
		std::cout << i << ' ';
	std::cout << "\n";

	for (auto i : _2tmp2)
		std::cout << i << ' ';
	std::cout << "\n";

	for (auto i : _2tmp3)
		std::cout << i << ' ';
	std::cout << "\n";

	std::cout << "\n3.\n\n";

	std::string str{ "32.e-80123" };
	std::string str2{ "e9" };
	std::string str3{ "3." };
	std::string str4{ "5-e+95" };
	std::string str5{ "9." };
	std::string str6{ ".-4" };
	std::string str7{ "+42e+76125" };
	std::string str8{ "+++" };

	std::cout << isNumber(str) << '\n' << isNumber(str2) << '\n' << isNumber(str3) << '\n'
		<< isNumber(str4) << '\n' << isNumber(str5) << '\n' << isNumber(str6) << '\n'
		<< isNumber(str7) << '\n' << isNumber(str8) << '\n';

	std::cout << "\nproductExceptSelf.\n\n";

	std::vector<int> arr{ 1, 2, 3, 4, 5 };
	arr = productExceptSelf(arr);

	for (auto i : arr)
		std::cout << i << '\n';

	return 0;
}

int singleNumber(std::vector<int>& nums)
{
	bool b = true;
	bool b2 = true;

	for (auto i : nums)
	{
		for (auto j : nums)
		{
			if (i == j && b)
			{
				b = false;
				continue;
			}
			if (i == j && !b)
			{
				b2 = false;
				break;
			}
		}
		if (b2)
			return i;
		b = true;
		b2 = true;
	}

	return -1;
}

std::vector<int> singleNumbers(std::vector<int>& nums)
{
	std::vector <int> tmp;
	bool b = true;
	bool b2 = true;

	for (auto i : nums)
	{
		for (auto j : nums)
		{
			if (i == j && b)
			{
				b = false;
				continue;
			}
			if (i == j && !b)
			{
				b2 = false;
				break;
			}
		}
		if (b2)
		{
			tmp.push_back(i);
		}
		b = true;
		b2 = true;
	}

	return tmp;
}

bool isNumber(std::string s)
{
	bool tiv{ false };
	char plus{ '+' };
	char minus{ '-' };
	char ket{ '.' };
	char eE{ 'e' };

	for (int i = 0; i < s.size();)
	{
		if (s[i] == plus && (minus || !(minus || eE)) || s[i] == '+')
		{
			if (plus == NULL)
			{
				if (s[0] == '+' && !eE && tiv)
				{
					++i;
					continue;
				}
				else
					return false;
			}
			else
			{
				plus = NULL;
				if (tiv && eE && '0' <= s[i + 1] && s[i + 1] <= '9')
					return false;
				if (s[i + 1] == '\0' || (s[i + 1] == '.' && s[i + 2] == '\0'))
					return false;
				if (!ket && eE)
					return false;
			}
		}
		else if (s[i] == minus && (plus || !(plus || eE)))
		{
			minus = NULL;
			if (tiv && eE && '0' <= s[i + 1] && s[i + 1] <= '9')
				return false;
			if (s[i + 1] == '\0' || (s[i + 1] == '.' && s[i + 2] == '\0'))
				return false;
			if (!ket && eE)
				return false;
		}
		else if (s[i] == ket && eE)
		{
			ket = NULL;
			++i;
			if (s[i] == '\0' && !tiv)
				return false;
			continue;
		}
		else if (tiv && (s[i] == eE || (s[i] == 'E' && eE)))
		{
			eE = NULL;
			++i;
			if (s[i] == '\0')
				return false;
			continue;
		}
		else if ('0' <= s[i] && s[i] <= '9')
		{
			tiv = true;
			if (s[i + 1] == '+' || s[i + 1] == '-')
				return false;
		}
		else
			return false;

		++i;
	}

	return true;
}

ListNode* mergeKLists(std::vector<ListNode*>& lists)
{
	/*ListNode list;
	ListNode* head = &list;
	ListNode* preHead = nullptr;

	int min = INT_MAX;
	int minInd = 0;

	bool b = true;

	while (b)
	{
		b = false;
		for (int i = 0; i < lists.size(); ++i)
		{
			if (lists[i] != nullptr)
			{
				b = true;
				if (min >= lists[i]->val)
				{
					min = lists[i]->val;
					minInd = i;
				}
			}
		}

		if (b)
		{
			head->val = min;
			head->next = new ListNode;
			preHead = head;
			head = head->next;
			if (lists[minInd] != nullptr)
				lists[minInd] = lists[minInd]->next;
		}
	}

	if (preHead != nullptr)
	{
		delete preHead->next;
		preHead->next = nullptr;
	}

	return &list;*/
	/*ListNode* head = nullptr;
	ListNode* list = nullptr;

	ListNode tmp{ INT_MAX };
	ListNode* min = &tmp;
	int minInd = 0;

	bool b = true;
	bool firstIter = true;

	while (b)
	{
		b = false;
		for (int i = 0; i < lists.size() - 1; ++i)
		{
			if (lists[i] != nullptr)
			{
				b = true;
				if (min->val >= lists[i]->val)
				{
					min = lists[i];
					lists[i] = lists[i]->next;
				}
			}
		}

		if (b)
		{
			head = min;
			if (firstIter)
				list = head;
			head = head->next;
		}
	}

	return list;*/

	return nullptr;
}

ListNode* deleteDuplicates(ListNode* head)
{
	if (head == nullptr)
		return head;
	ListNode* headCpy = head;
	while (head->next != nullptr)
	{
		if (head->val == head->next->val)
			head->next = head->next->next;
		else
			head = head->next;
	}

	return headCpy;
}

bool isPalindrome(ListNode* head)
{
	if (head == nullptr)
		return false;
	if (head->next == nullptr)
		return true;

	ListNode* tmp = head;

	int size = 1;
	for (; tmp->next != nullptr; tmp = tmp->next, ++size);
	tmp = head;

	int* arr = new int[size];

	for (int i = 0; i < size; ++i, tmp = tmp->next)
		arr[i] = tmp->val;

	for (int i = 0; i < size / 2; ++i)
		if (arr[i] != arr[size - i - 1])
			return false;

	return true;
}

ListNode* removeElements(ListNode* head, int val)
{
	if (head == nullptr)
		return head;

	ListNode* headCpy = head;

	while (head->next != nullptr)
	{
		if (head->next->val == val)
		{
			head->next = head->next->next;
			continue;
		}
		head = head->next;
	}

	if (headCpy->val == val)
		headCpy = headCpy->next;

	return headCpy;
}

ListNode* reverseList(ListNode* head)
{
	if (head == nullptr)
		return head;
	if (head->next == nullptr)
		return head;

	ListNode* tmp = head;

	int size = 1;
	for (; tmp->next != nullptr; tmp = tmp->next, ++size);
	tmp = head;

	int* arr = new int[size];

	for (int i = size - 1; i >= 0; --i, tmp = tmp->next)
		arr[i] = tmp->val;
	tmp = head;

	for (int i = 0; i < size; ++i, tmp = tmp->next)
		tmp->val = arr[i];

	return head;
}

ListNode* getIntersectionNode(ListNode* headA, ListNode* headB)
{
	if (headA == nullptr || headB == nullptr)
		return nullptr;

	ListNode* A = headA;
	ListNode* B = headB;

	while (headA != nullptr)
	{
		if (headA == headB)
			return headA;
		headB = headB->next;
		if (headB == nullptr)
		{
			headA = headA->next;
			headB = B;
		}
	}

	return nullptr;
}

void deleteNode(ListNode* node)
{
	node->val = node->next->val;
	node->next = node->next->next;
}

bool hasCycle(ListNode* head)
{
	if (head == nullptr)
		return false;

	ListNode* slow = head;
	ListNode* fast = head->next;

	while (slow != nullptr && fast != nullptr)
	{
		if (slow == fast)
			return true;
		slow = slow->next;
		if (fast->next == nullptr)
			return false;
		else
			fast = fast->next->next;
	}

	return false;
}

std::vector<int> productExceptSelf(std::vector<int>& nums)
{
	std::vector<int> vec;
	int num = 1;

	for (int i = 0, j = 0, k = i + 1; i < nums.size(); ++j, ++k)
	{
		if (j < i && k < nums.size())
			num *= nums[j] * nums[k];
		else if (j < i)
			num *= nums[j];
		else if (k < nums.size())
			num *= nums[k];
		else
		{
			vec.push_back(num);
			++i;
			j = -1;
			k = i;
			num = 1;
		}
	}

	return vec;
}