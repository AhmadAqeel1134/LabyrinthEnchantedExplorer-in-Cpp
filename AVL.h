#pragma once
#include<iostream>
#include<string>
using namespace std;

class GameNode
{
public:
    int key;
    string name;
    GameNode()
    {
        key = 0;
        name = "";
    }
    GameNode(int key,string name)
    {
        this->key = key;
        this->name = name;
    }
};

class AVLNode
{
public:
    AVLNode* leftNode;
    AVLNode* rightNode;
    GameNode* obj;
    int height;
   
    AVLNode()
    {
        leftNode = NULL;
        rightNode = NULL;
       this->height = 1;
     
    }
    AVLNode(GameNode *obj)
    {
        this->obj=obj;
        rightNode = NULL;
        leftNode = NULL;
        this->height = 1;
    }
};

class AVLTree
{
public:
    AVLNode* PassedNode;


    int Largest(AVLNode* PassedNode)
    {
        if (PassedNode->rightNode == NULL)
            return PassedNode->obj->key;
        return Largest(PassedNode->rightNode);
    }

    int Smallest(AVLNode* PassedNode)
    {
        if (PassedNode->leftNode == NULL)
            return PassedNode->obj->key;
        return Smallest(PassedNode->leftNode);
    }


    int max(int a, int b)
    {
        if (a > b)
            return a;
        return b;
    }

    int AVLHeight(AVLNode* PassedNode)
    {
        if (PassedNode == NULL)
            return 0;
        return PassedNode->height;
    }

    int AVLBalanceFactor(AVLNode* PassedNode)
    {
        if (PassedNode == NULL)
            return 0;
        return AVLHeight(PassedNode->leftNode) - AVLHeight(PassedNode->rightNode);
    }
    void display()
    {
        preorder(PassedNode);
    }

    void preorder(AVLNode* root)
    {
        if (root == NULL)
            return;
        cout << root->obj->key << " " << root->obj->name << endl;;
        preorder(root->leftNode);
        preorder(root->rightNode);
    }

    void LeftRotate(AVLNode*& PassedNode)
    {
        AVLNode* TempNode = PassedNode->rightNode;
        PassedNode->rightNode = TempNode->leftNode;
        TempNode->leftNode = PassedNode;
        PassedNode->height = 1 + max(AVLHeight(PassedNode->leftNode), AVLHeight(PassedNode->rightNode));
        TempNode->height = 1 + max(AVLHeight(TempNode->leftNode), AVLHeight(TempNode->rightNode));
        PassedNode = TempNode;
    }

    void RightRotate(AVLNode*& PassedNode)
    {
        AVLNode* TempNode = PassedNode->leftNode;
        PassedNode->leftNode = TempNode->rightNode;
        TempNode->rightNode = PassedNode;
        PassedNode->height = 1 + max(AVLHeight(PassedNode->leftNode), AVLHeight(PassedNode->rightNode));
        TempNode->height = 1 + max(AVLHeight(TempNode->leftNode), AVLHeight(TempNode->rightNode));
        PassedNode = TempNode;
    }

    void LRAVLTree(AVLNode*& PassedNode)
    {
        LeftRotate(PassedNode->leftNode);
        RightRotate(PassedNode);
    }

    void RLAVLTree(AVLNode*& PassedNode)
    {
        RightRotate(PassedNode->rightNode);
        LeftRotate(PassedNode);
    }

    void AVLRebalance(AVLNode*& PassedNode)
    {
        int balance = AVLBalanceFactor(PassedNode);
        if (balance > 1)
        {
            if (AVLBalanceFactor(PassedNode->leftNode) < 0)
                LRAVLTree(PassedNode);
            else
                RightRotate(PassedNode);
        }
        else if (balance < -1)
        {
            if (AVLBalanceFactor(PassedNode->rightNode) > 0)
                RLAVLTree(PassedNode);
            else
                LeftRotate(PassedNode);
        }
    }

    void AVLInsert(AVLNode*& PassedNode, int data,string name)
    {
        GameNode* gameNode = new GameNode(data, name);
        AVLNode* newNode = new AVLNode(gameNode);
        if (PassedNode == NULL)
        {
            PassedNode = newNode;
            return;
        }
        if (data < PassedNode->obj->key)
            AVLInsert(PassedNode->leftNode, data,name);
        else
            AVLInsert(PassedNode->rightNode, data,name);
        PassedNode->height = 1 + max(AVLHeight(PassedNode->leftNode), AVLHeight(PassedNode->rightNode));
        AVLRebalance(PassedNode);
    }

    void AVLDelete(AVLNode*& PassedNode, int data, string name)
    {
        if (PassedNode == NULL)
            return;
        if (data < PassedNode->obj->key)
            AVLDelete(PassedNode->leftNode, data,name);
        else if (data > PassedNode->obj->key)
            AVLDelete(PassedNode->rightNode, data,name);
        else
        {
            if (PassedNode->leftNode== NULL && PassedNode->rightNode == NULL)
            {
                delete PassedNode;
                PassedNode = NULL;
            }
            else if (PassedNode->leftNode == NULL)
            {
                AVLNode* TempNode = PassedNode;
                PassedNode = PassedNode->rightNode;
                delete TempNode;
            }
            else if (PassedNode->rightNode == NULL)
            {
                AVLNode* TempNode = PassedNode;
                PassedNode = PassedNode->leftNode;
                delete TempNode;
            }
            else
            {
                PassedNode->obj->key = Largest(PassedNode->leftNode);
                AVLDelete(PassedNode->leftNode, PassedNode->obj->key,PassedNode->obj->name);
            }
        }
        if (PassedNode == NULL)
            return;
        PassedNode->height = 1 + max(AVLHeight(PassedNode->leftNode), AVLHeight(PassedNode->rightNode));
        AVLRebalance(PassedNode);
    }

    bool SearchInInventory(AVLNode* node, int key)
    {
        if (node == nullptr)
            return false;

        if (node->obj->key == key)
            return true;
        else if (key < node->obj->key)
            return SearchInInventory(node->leftNode, key);
        else
            return SearchInInventory(node->rightNode, key);
    }
   
public:
    AVLTree() : PassedNode(nullptr) {}

    void insert(int key,string name)
    {
        AVLInsert(PassedNode, key,name);
    }
    bool SearchInInventory(int key)
    {
        return SearchInInventory(PassedNode, key);
    }

    void remove(int Data,string name)
    {
        AVLDelete(PassedNode, Data,name);
    }
};
