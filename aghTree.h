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

    /// \brief Metoda zwraca wska�nik do ��danego w�z�a
    ///
    /// \param n - indeks w�z�a
    /// \return wska�nik do w�z�a
    aghNode<T>* getNodePtr(int n) const;
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
    /// \return zwraca ilo�� element�w element�w
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
    
}
// ---------------------------------------------------------------

template <class T>
aghTree<T>::aghTree()
{
    root = nullptr;
    amount = 0;
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
   
}
// ---------------------------------------------------------------

template <class T>
T& aghTree<T>::at(int n) const
{
    T* k = new T();
    return *k;

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
