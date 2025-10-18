#pragma once


template<class TKey, class TVal>
struct BTreeNode
{
	TKey key;
	TVal value;
	BTreeNode* left  = nullptr;
	BTreeNode* right = nullptr;


	BTreeNode(const TKey& key, const TVal& value) : key(key), value(value) { }

	void print()
	{
		if (left != nullptr) left->print();
		cout << value << " ";
		if (right != nullptr) right->print();
	}

	void del()
	{
		if (left != nullptr) left->del();
		if (right != nullptr) right->del();
		delete this;
	}


	TVal* getValue(const TKey& key)
	{
		if (key == this->key) return &value;
		else if (key < this->key && left != nullptr) left->getValue(key);
		else if (key > this->key && right != nullptr) right->getValue(key);
		else return nullptr;
	}
};


template<class TKey, class TVal>
class BTree
{
	bool isPush = false;

	BTreeNode<TKey, TVal>* root = nullptr;

	BTreeNode<TKey, TVal>* push_r(const TKey& key, const TVal& value, BTreeNode<TKey, TVal>*& node);
	BTreeNode<TKey, TVal>* remove(const TKey& key, BTreeNode<TKey, TVal>*& node);


public:
	~BTree();
	void clear();
	void print();
	bool push(const TKey& key, const TVal& value);
	TVal* getValue(const TKey& key);

	bool push_r(const TKey& key, const TVal& value);
	bool remove(const TKey& key);

};

template<class TKey, class TVal>
BTreeNode<TKey, TVal>* BTree<TKey, TVal>::push_r(const TKey& key, const TVal& value, BTreeNode<TKey, TVal>*& node)
{
	if (!node)
	{
		node = new BTreeNode<TKey, TVal>(key, value);
		isPush = true;
		return node;
	}

	if (key == node->key)
	{
		isPush = false;
	}
	else if (key < node->key)
		node->left = push_r(key, value, node->left);
	else if (key > node->key)
		node->right = push_r(key, value, node->right);
	return node;
}

template<class TKey, class TVal>
BTree<TKey, TVal>::~BTree()
{
	clear();
}

template<class TKey, class TVal>
void BTree<TKey, TVal>::clear()
{
	if (root) root->del();
}

template<class TKey, class TVal>
void BTree<TKey, TVal>::print()
{
	if (root) root->print();
}

template<class TKey, class TVal>
bool BTree<TKey, TVal>::push(const TKey& key, const TVal& value)
{
	if (!root)
	{
		root = new BTreeNode<TKey, TVal>(key, value);
		return true;
	}

	BTreeNode<TKey, TVal>* current = root;
	do
	{
		if (key < current->key)
		{
			if (current->left)
			{
				current = current->left;
			}
			else
			{
				current->left = new BTreeNode<TKey, TVal>(key, value);
				return true;
			}
		}
		else if (key > current->key)
		{
			if (current->right)
			{
				current = current->right;
			}
			else
			{
				current->right = new BTreeNode<TKey, TVal>(key, value);
				return true;
			}
		}
		else
		{
			return false;
		}
	} while (true);
}

template<class TKey, class TVal>
TVal* BTree<TKey, TVal>::getValue(const TKey& key)
{
	if (root)
		return root->getValue(key);
	return nullptr;
}

template<class TKey, class TVal>
bool BTree<TKey, TVal>::push_r(const TKey& key, const TVal& value)
{
	push_r(key, value, root);
	return isPush;
}

template<class TKey, class TVal>
bool BTree<TKey, TVal>::remove(const TKey& key)
{
	return remove(key, root);
}

template<class TKey, class TVal>
BTreeNode<TKey, TVal>* BTree<TKey, TVal>::remove(const TKey& key, BTreeNode<TKey, TVal>*& node)
{
	BTreeNode<TKey, TVal>* tmp; //запоминаем найденный узел
	BTreeNode<TKey, TVal>* next;
	if (!node)
		cout << "Item not found";
	else
		if (key < node->key) //искомое меньше
			node->left = remove(key, node->left);        //идем по левому плечу
		else
			if (key > node->key) //искомое больше
				node->right = remove(key, node->right);  //идем по правому плечу
			else
			{
				tmp = node;            //запоминаем найденный узел
				if (!node->right)
					node = node->left; //случай 1
				else if (!node->left)
					node = node->right; //случай 1
				else
				{   //случай 2
					next = node->left; //выбираем левую ветку
					if (next->right) { //правая ветка не пуста
						while (next->right->right)
							next = next->right;
						//перемещаемся до последнего справа
						node->key = next->right->key;
						node->value = next->right->value;
						//записываем значение
						tmp = next->right; //этот узел удалить
						next->right = next->right->left; //присоединить
					}
					else
					{//дальше нету веток
						node->key = next->key;
						tmp = next; //этот узел удалить
						node->left = node->left->left;
					}
				}
				delete tmp;
			}
	return node;
}