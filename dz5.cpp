#include <iostream>

using namespace std;

class Set
{
	private:
		struct Node
		{
			int num;
			Node *next;
			Node ()
			{
				next=NULL;
			}
		{;
	public:
		Node *first;
		Set()
		{
			first=NULL;
		}
		void Add(int nnum)
		{
			Node* addNode = new Node;
			addNode->num=nnum;
			if (first!=NULL)
				GetLast()->next = addNode;
			else
				first = addNode; 
		}

		Node *GetLast()
		{
			Node *current = first;
			if (current==NULL)
				return NULL;
			while (current->next!=NULL)
				current = current->next;
			return current;
		}
		int operator [](int i)
		{
			Node* current = first;
			for (int j=0; j<i-1; ++j)
				current = current->next;
			return current->num; 
		}
		int count()
		{
			Node *current = first;
			int i=0; 
			while (current->next!=NULL)
			{
				current = current->next;
				i++;
			}
			return i+1;
		}
		void DeleteNode(int i)
		{
			Node *current = first;
			if (i==1)
			{
				first = current->next;
				delete[] current; 
			}
			else
			for (int j=1; j<i-1; j++)
				current = current->next;
			Node *temp = current->next;
			current->next = temp->next;
			delete []temp;
		}
		Set operator+(Set);
		Set operator-(Set);
		Set operator*(Set);
		Set operator=(Set);
		Set Magic (Set,Set);
		Set operator^(Set);
};
Set Set::operator^(Set s)
{
	Set *temp = new Set;
	(*temp)=(*this)*s;
	Set *temp2 = new Set;
	(*temp2)=(*this)+s;
	(*temp)=(*temp2)-(*temp);
	return *temp;
}

Set Set::operator=(Set s)
{
	for (int i=1; i<s.count()+1; ++i)
		(*this).Add(s[i]);
	return *this; 
}
Set Set::operator*(Set s)
{
	Set *temp = new Set;
	Set *temp2 = new Set;
	temp2 = this;
	for (int i=1; i<(*temp2).count()+1;++i)
		for (int k=1; k<s.count()+1; ++k)
			if ((*temp2)[i]==s[k])
				(*temp).Add(s[k]);
	delete [] temp2;
	return *temp; 
}

Set Set::operator-(Set s)
{
	Set *temp = new Set;
	Set *temp2 = new Set;
	temp2 = this;
	for (int i=1; i<(*temp2).count()+1;++i)
		(*temp).Add((*temp2)[i]);
	for (int j=1; j<(*temp2).count()+1;++j)
		for (int k=1; k<(*temp).count()+1; ++k)
			if (s[j]==(*temp)[k])
				(*temp).DeleteNode(k);
	delete [] temp2;
	return *temp;
}
Set Set::operator+(Set s)
{
	Set *temp = new Set;
	Set *temp2 = new Set;
	temp2 = this;
	for (int j=1; j<(*temp2).count()+1;++j)
		(*temp).Add((*temp2)[j]);
	for (int i=1; i<s.count()+1;++i)
		(*temp).Add(s[i]);		
	delete [] temp2;
	return *temp;
}
ostream& operator<<(ostream &os, Set& s)
{
	for (int i=1; i<s.count()+1;++i)
		os << s[i]<<endl;
	return os;
}
Set Magic(Set s, Set ss)
{
	Set *temp = new Set;
	(*temp)=(s+ss)-(s*ss);
	return *temp;
}

int main ()
{
Set *sset = new Set;
Set *aset = new Set;
(*aset).Add(6); 
(*aset).Add(42); 
(*sset).Add(33); 
(*sset).Add(6); 
Set *ss = new Set;
(*ss)=(*sset)^(*aset);
//(*ss)=Magic((*sset),(*aset));
cout<<(*ss);
return 0;
}