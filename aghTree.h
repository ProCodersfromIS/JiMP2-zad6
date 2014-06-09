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

    /// \brief Metoda zwraca wskaŸnik do ¿¹danego wêz³a
    ///
    /// \param n - indeks wêz³a
    /// \return wskaŸnik do wêz³a
    aghNode<T>* getNodePtr(int n) const;
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
    /// \return zwraca iloœæ elementów elementów
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
