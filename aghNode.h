/**
* \file aghNode.h
* \author Beata Gie�baga & Kamil Dawid�w
* \date 09.06.2014
* \brief Deklaracja i definicja szablonu klasy aghNode
*/
// -------------------------------------------------------------------------

#ifndef AGHNODE_H
#define AGHNODE_H
// -------------------------------------------------------------------------

/**
* \class aghNode
* \author Beata Gie�baga & Kamil Dawid�w
* \date 09.06.2014
* \brief szablon klasy aghNode implementuj�cej w�ze� BST
// -------------------------------------------------------------------------
*/
template <class T>
class aghNode
{
private:
    T data; ///< dane zapisane w w�le
    aghNode<T>* parent; ///< wska�nik do w�z�a rodzica
    aghNode<T>* left; ///< wska�nik do w�z�a po lewej
    aghNode<T>* right; ///< wska�nik do w�z�a po prawej

public:

    /// \brief Konstruktor bezparametrowy
    aghNode();

    /// \brief Konstruktor parametrowy
    ///
    /// \param _data = warto��, kt�r� przyjmie pole data
    aghNode(T _data);

    /// \brief Destruktor
    ~aghNode();

    /// \brief Metoda ustawia zapisane dane
    ///
    /// \param _data - referencja do danych
    void setData(const T& _data);

    /// \brief Metoda zwraca referencj� do zapisanych danych
    T& getData(void);

    /// \brief Metoda zmienia warto�� pola parent
    ///
    /// \param _parent - nowa warto�� pola parent
    void setParent(aghNode<T>* const _parent);

    /// \brief Metoda zwraca warto�� pola parent
    ///
    /// \return - warto�� pola parent
    aghNode<T>* getParent(void) const;

    /// \brief Metoda zmienia warto�� pola left
    ///
    /// \param _left - nowa warto�� pola left
    void setLeft(aghNode<T>* const _left);

    /// \brief Metoda zwraca warto�� pola left
    ///
    /// \return - warto�� pola left
    aghNode<T>* getLeft(void) const;

    /// \brief Metoda zmienia warto�� pola right
    ///
    /// \param _right - nowa warto�� pola right
    void setRight(aghNode<T>* const _right);

    /// \brief Metoda zwraca warto�� pola right
    ///
    /// \return - warto�� pola Right
    aghNode<T>* getRight(void) const;
};
// ---------------------------------------------------------------

// Definicje metod szablonu
// ---------------------------------------------------------------

template <class T>
aghNode<T>::aghNode()
{
    parent = nullptr;
    left = nullptr;
    right = nullptr;
}
// ---------------------------------------------------------------

template <class T>
aghNode<T>::aghNode(T _data)
{
    parent = nullptr;
    left = nullptr;
    right = nullptr;
    data = _data;
}
// ---------------------------------------------------------------

template <class T>
aghNode<T>::~aghNode()
{

}
// ---------------------------------------------------------------

template <class T>
void aghNode<T>::setData(const T& _data)
{
    data = _data;
}
// ---------------------------------------------------------------

template <class T>
T& aghNode<T>::getData(void)
{
    return data;
}
// ---------------------------------------------------------------

template <class T>
void aghNode<T>::setParent(aghNode<T>* const _parent)
{
    parent = _parent;
}
// ---------------------------------------------------------------

template <class T>
aghNode<T>* aghNode<T>::getParent(void) const
{
    return parent;
}
// ---------------------------------------------------------------

template <class T>
void aghNode<T>::setLeft(aghNode<T>* const _left)
{
    left = _left;
}
// ---------------------------------------------------------------

template <class T>
aghNode<T>* aghNode<T>::getLeft(void) const
{
    return left;
}
// ---------------------------------------------------------------

template <class T>
void aghNode<T>::setRight(aghNode<T>* const _right)
{
    right = _right;
}
// ---------------------------------------------------------------

template <class T>
aghNode<T>* aghNode<T>::getRight(void) const
{
    return right;
}
// ---------------------------------------------------------------

#endif
