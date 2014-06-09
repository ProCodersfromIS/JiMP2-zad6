/**
* \file aghTree.h
* \author Beata Gie³baga & Kamil Dawidów
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
* \author Beata Gie³baga & Kamil Dawidów
* \date 03.06.2014
* \brief Szablon klasy aghTree implementuj¹cej BST
// -------------------------------------------------------------------------
*/
template <class T>
class aghTree : public aghContainer<T>
{
private:
    aghNode<T>* root = nullptr; ///< wskaŸnik do korzenia
    int amount = 0; ///< iloœæ elementów w drzewie

    /// \brief Metoda zwraca wskaŸnik do ¿¹danego wêz³a (in-order)
    ///
    /// \param n - indeks wêz³a
    /// \return wskaŸnik do wêz³a
    aghNode<T>* getNodePtr(int n) const;

    aghNode<T>* findMinNode(aghNode<T>* temp);

    aghNode<T>* findReplacer(aghNode<T>* temp);


public:
    /// \brief Konstruktor bezparametrowy
    aghTree();

    /// \brief Konstruktor kopiuj¹cy
    ///
    /// \param pattern - referencja do obiektu macierzystego
    aghTree(const aghTree<T>& pattern);

    /// \brief Konstruktor kopiuj¹cy przyjmuj¹cy jako argument referencjê do obiektu klasy aghContainer
    ///
    /// \param pattern - referencja do obiektu macierzystego
    aghTree(const aghContainer<T>& pattern);

    /// \brief Destruktor
    ~aghTree();

    /// \brief Metoda  zwraca wartoœæ elementu
    ///
    /// \param n - indeks zwracanego elementu
    T& at(int n) const;

    /// \brief Metoda  zwraca iloœæ elementów w pojemniku
    ///
    /// \return zwraca iloœæ elementów
    int size(void) const;

    /// \brief Metoda wstawia element do drzewa
    /// 
    /// \param n - ignorowany
    /// \param element - referencja do elementu, który zostanie wstawiony
    /// \return metoda zwraca:
    /// \li true - gdy uda siê wstawiæ element
    /// \li false - gdy nie uda siê wstawiæ elementu
    bool insert(int n, T const& element);

    /// \brief Metoda usuwa wybrany element
    ///
    /// \param n - indeks usuwanego elementu
    /// \return zwraca:
    /// \li true - gdy uda siê usun¹æ element
    /// \li false - gdy nie uda siê usun¹æ elementu
    bool remove(int n);

    /// \brief Prze³adowanie operatora przypisania "="
    ///
    /// \param right - referencja do obiektu macierzystego
    /// \return zwraca referencjê do obiektu macierzystego
    aghTree<T>& operator=(aghTree<T> const& right);

};
// -------------------------------------------------------------------------
// Definicje metod szablonu
// -------------------------------------------------------------------------

template <class T>
aghNode<T>* aghTree<T>::getNodePtr(int n) const
{
    aghNode<T>* result = nullptr;
    aghNode<T>* it = root;
    aghNode<T>* visited = nullptr;
    int counter = -1;

    while (!result)
    {
        if (visited == it->getParent())
        {
            visited = it;
            if (it->getLeft())
                it = it->getLeft();
            else
            {
                ++counter;
                if (n == counter)
                    result = it;
                if (it->getRight())
                    it = it->getRight();
                else
                    it = it->getParent();
            }
        }
        else if (visited == it->getLeft())
        {
            visited = it;
            ++counter;
            if (n == counter)
                result = it;
            if (it->getRight())
                it = it->getRight();
            else
                it = it->getParent();
        }
        else //if (visited == it->getRight())
        {
            visited = it;
            it = it->getParent();
        }
    }
    return result;
}
// ---------------------------------------------------------------

template <class T>
aghNode<T>* aghTree<T>::findMinNode(aghNode<T>* temp)
{
    aghNode<T>* it = temp;
    if (!it)
        return nullptr;
    while (1)
    {
        if (it->getLeft())
            it = it->getLeft();
        else
            break;
    }
    return it;
}
// ---------------------------------------------------------------

template <class T>
aghNode<T>* aghTree<T>::findReplacer(aghNode<T>* temp)
{
    aghNode<T>* it temp->getRight();
    if (!it)
        return nullptr;
    else
        return this->findMinNode(it);
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
