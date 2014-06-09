/**
* \file aghNode.h
* \author Beata Gie³baga & Kamil Dawidów
* \date 09.06.2014
* \brief Deklaracja i definicja szablonu klasy aghNode
*/
// -------------------------------------------------------------------------

#ifndef AGHNODE_H
#define AGHNODE_H
// -------------------------------------------------------------------------

/**
* \class aghNode
* \author Beata Gie³baga & Kamil Dawidów
* \date 09.06.2014
* \brief szablon klasy aghNode implementuj¹cej wêze³ BST
// -------------------------------------------------------------------------
*/
template <class T>
class aghNode
{
private:
    T data; ///< dane zapisane w wêŸle
    aghNode<T>* parent; ///< wskaŸnik do wêz³a rodzica
    aghNode<T>* left; ///< wskaŸnik do wêz³a po lewej
    aghNode<T>* right; ///< wskaŸnik do wêz³a po prawej

public:

    /// \brief Konstruktor bezparametrowy
    aghNode();

    /// \brief Konstruktor parametrowy
    ///
    /// \param _data = wartoœæ, któr¹ przyjmie pole data
    aghNode(T _data);

    /// \brief Destruktor
    ~aghNode();

    /// \brief Metoda ustawia zapisane dane
    ///
    /// \param _data - referencja do danych
    void setData(const T& _data);

    /// \brief Metoda zwraca referencjê do zapisanych danych
    T& getData(void);

    /// \brief Metoda zmienia wartoœæ pola parent
    ///
    /// \param _parent - nowa wartoœæ pola parent
    void setParent(aghNode<T>* const _parent);

    /// \brief Metoda zwraca wartoœæ pola parent
    ///
    /// \return - wartoœæ pola parent
    aghNode<T>* getParent(void) const;

    /// \brief Metoda zmienia wartoœæ pola left
    ///
    /// \param _left - nowa wartoœæ pola left
    void setLeft(aghNode<T>* const _left);

    /// \brief Metoda zwraca wartoœæ pola left
    ///
    /// \return - wartoœæ pola left
    aghNode<T>* getLeft(void) const;

    /// \brief Metoda zmienia wartoœæ pola right
    ///
    /// \param _right - nowa wartoœæ pola right
    void setRight(aghNode<T>* const _right);

    /// \brief Metoda zwraca wartoœæ pola right
    ///
    /// \return - wartoœæ pola Right
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
