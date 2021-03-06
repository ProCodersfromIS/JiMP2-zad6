/**
* \file aghTree.h
* \author Beata Gie�baga & Kamil Dawid�w
* \date 09.06.2014
* \brief Deklaracja i definicja szablonu klasy aghTree
*/
// -------------------------------------------------------------------------

#ifndef AGHTREE_H
#define AGHTREE_H
// -------------------------------------------------------------------------

#include "aghNode.h"
#include "aghContainer.h"
// -------------------------------------------------------------------------

/**
* \class aghTree
* \author Beata Gie�baga & Kamil Dawid�w
* \date 03.06.2014
* \brief Szablon klasy aghTree implementuj�cej BST
// -------------------------------------------------------------------------
*/
template <class T>
class aghTree : public aghContainer<T>
{
private:
    aghNode<T>* root = nullptr; ///< wska�nik do korzenia
    int amount = 0; ///< ilo�� element�w w drzewie

    /// \brief Metoda zwraca wska�nik do ��danego w�z�a (in-order)
    ///
    /// \param n - indeks w�z�a
    /// \return wska�nik do w�z�a
    aghNode<T>* getNodePtr(int n) const;

    /// \brief Metoda usuwa dany w�ze�
    ///
    /// \param target - wska�nik do w�z�a
    void deleteNode(aghNode<T>* target);

    /// \brief Metoda znajduje potomka prawego dziecka o najmniejszej warto�ci
    ///
    /// \return wska�nik do szukanego w�z�a
    aghNode<T>* getReplacer(aghNode<T>* temp);


public:
    /// \brief Konstruktor bezparametrowy
    aghTree();

    /// \brief Konstruktor kopiuj�cy
    ///
    /// \param pattern - referencja do obiektu macierzystego
    aghTree(const aghTree<T>& pattern);

    /// \brief Konstruktor kopiuj�cy przyjmuj�cy jako argument referencj� do obiektu klasy aghContainer
    ///
    /// \param pattern - referencja do obiektu macierzystego
    aghTree(const aghContainer<T>& pattern);

    /// \brief Destruktor
    ~aghTree();

    /// \brief Metoda  zwraca warto�� elementu
    ///
    /// \param n - indeks zwracanego elementu
    T& at(int n) const;

    /// \brief Metoda  zwraca ilo�� element�w w pojemniku
    ///
    /// \return zwraca ilo�� element�w
    int size(void) const;

    /// \brief Metoda wstawia element do drzewa
    /// 
    /// \param n - ignorowany
    /// \param element - referencja do elementu, kt�ry zostanie wstawiony
    /// \return metoda zwraca:
    /// \li true - gdy uda si� wstawi� element
    /// \li false - gdy nie uda si� wstawi� elementu
    bool insert(int n, T const& element);

    /// \brief Metoda usuwa wybrany element
    ///
    /// \param n - indeks usuwanego elementu
    /// \return zwraca:
    /// \li true - gdy uda si� usun�� element
    /// \li false - gdy nie uda si� usun�� elementu
    bool remove(int n);

    /// \brief Prze�adowanie operatora przypisania "="
    ///
    /// \param right - referencja do obiektu macierzystego
    /// \return zwraca referencj� do obiektu macierzystego
    aghTree<T>& operator=(aghTree<T> const& right);

};
// -------------------------------------------------------------------------
// Definicje metod szablonu
// -------------------------------------------------------------------------

template <class T>
aghNode<T>* aghTree<T>::getNodePtr(int n) const
{
    aghNode<T>* it = root;
    aghNode<T>* prev = nullptr;
    int counter = -1;

    while (it)
    {
        if (prev == it->getParent())
        {
            prev = it;
            if (it->getLeft())
                it = it->getLeft();
            else
            {
                if (n == ++counter)
                    break;
                if (it->getRight())
                    it = it->getRight();
                else
                    it = it->getParent();
            }
        }
        else if (prev == it->getLeft())
        {
            prev = it;
            if (n == ++counter)
                break;
            if (it->getRight())
                it = it->getRight();
            else
                it = it->getParent();
        }
        else
        {
            prev = it;
            it = it->getParent();
        }
    }
    return it;
}
// ---------------------------------------------------------------

template <class T>
void aghTree<T>::deleteNode(aghNode<T>* target)
{
    
    aghNode<T>* lChild = target->getLeft();
    aghNode<T>* rChild = target->getRight();
    aghNode<T>* parent = target->getParent();

    //has no children
    if (!lChild && !rChild)
    {
        //has parent
        if (parent)
        {
            //is left child
            if (parent->getLeft() == target)
                parent->setLeft(nullptr);
            //is right child
            else
                parent->setRight(nullptr);
        }
        //no parent
        else
            root = nullptr;
    }
    //has one children
    else if ((lChild && !rChild) || (!lChild && rChild))
    {
        //has left child
        if (lChild && !rChild)
        {
            //has parent
            if (parent)
            {
                lChild->setParent(parent);
                //is left child
                if (parent->getLeft() == target)
                    parent->setLeft(lChild);
                //is right child
                else
                    parent->setRight(lChild);
            }
            //no parent
            else
            {
                root = lChild;
                lChild->setParent(nullptr);
            }
        }
        //has right child
        else if (!lChild && rChild)
        {
            //has parent
            if (parent)
            {
                rChild->setParent(parent);
                //is left child
                if (parent->getLeft() == target)
                    parent->setLeft(rChild);
                //is right child
                else
                    parent->setRight(rChild);
            }
            //no parent
            else
            {
                root = rChild;
                rChild->setParent(nullptr);
            }
        }
    }
    //has two children
    else if (lChild && rChild)
    {
        aghNode<T>* replacer = this->getReplacer(target);
        target->setData(replacer->getData());
        this->deleteNode(replacer);
    }

    --amount;
    delete target;
}
// ---------------------------------------------------------------

template <class T>
aghNode<T>* aghTree<T>::getReplacer(aghNode<T>* temp)
{
    aghNode<T>* it = temp->getRight();
    if (!it)
        return nullptr;
    if (it->getRight())
    {
        it = it->getRight();
        while (1)
        {
            if (it->getLeft())
                it = it->getLeft();
            else
                break;
        }
    }
    return it;
}
// ---------------------------------------------------------------

template <class T>
aghTree<T>::aghTree()
{
}
// ---------------------------------------------------------------

template <class T>
aghTree<T>::aghTree(const aghTree<T>& pattern)
{
    this->operator=(pattern);
}
// ---------------------------------------------------------------

template <class T>
aghTree<T>::aghTree(const aghContainer<T>& pattern)
{
   this->aghContainer<T>::operator=(pattern);
}
// --------------------------------------------------------------

template <class T>
aghTree<T>::~aghTree()
{
    if (root)
        this->clear();
}
// ---------------------------------------------------------------

template <class T>
T& aghTree<T>::at(int n) const
{
    if (this->invalidIndex(n))
        throw aghException(0, "Index out of range", __FILE__, __LINE__);

    return this->getNodePtr(n)->getData();
}
// --------------------------------------------------------------

template <class T>
int aghTree<T>::size(void) const
{
    return amount;
}
// ---------------------------------------------------------------

template <class T>
bool aghTree<T>::insert(int n, T const& element)
{
    if (root == nullptr)
        root = new aghNode<T>(element);
    else
    {
        aghNode<T>* it = root;
        aghNode<T>* helper = root;

        while (it)
        {
            helper = it;
            if (element < it->getData())
                it = it->getLeft();
            else
                it = it->getRight();
        }

        if (element < helper->getData())
        {
            helper->setLeft(new aghNode<T>(element));
            helper->getLeft()->setParent(helper);
        }
        else
        {
            helper->setRight(new aghNode<T>(element));
            helper->getRight()->setParent(helper);
        }
    }

    ++amount;
    return true;
}
// --------------------------------------------------------------

template <class T>
bool aghTree<T>::remove(int n)
{
    if (this->invalidIndex(n))
        return false;

    this->deleteNode(this->getNodePtr(n));
    return true;
}
// ---------------------------------------------------------------

template <class T>
aghTree<T>& aghTree<T>::operator=(const aghTree<T>& right)
{
    this->aghContainer<T>::operator=(right);
    return *this;
}
// ---------------------------------------------------------------

#endif
