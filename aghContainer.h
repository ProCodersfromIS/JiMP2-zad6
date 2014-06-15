/**
* \file aghContainer.h
* \author Beata Gie�baga & Kamil Dawid�w
* \date 26.05.2014
* \brief Deklaracja i definicja szablonu klasy abstrakcyjnej aghContainer
*/
// -------------------------------------------------------------------------

#ifndef AGHCONTAINER_H
#define AGHCONTAINER_H
// ------------------------------

/**
* \class aghContainer
* \author Beata Gie�baga & Kamil Dawid�w
* \date 26.05.2014
* \brief Szablon klasy abstrakcyjnej aghContainer - pojemnika
*/
// -------------------------------------------------------------------------
template <class T>
class aghContainer
{
protected:
    /// \brief Metoda sprawdza, czy przekazany indeks jest poprawny
    ///
    /// \param n - indeks
    /// \return metoda zwraca:
    /// \li true - gdy indeks jest w zakresie wektora
    /// \li false - gdy indeks nie jest w zakresie wektora
    bool invalidIndex(int n) const;

public:
    /// \brief Konstruktor bezparametrowy
    aghContainer();

    /// \brief Destruktor wirtualny
    virtual ~aghContainer();

    /// \brief Metoda dodaje element do pojemnika
    ///
    /// \param element - referencja do elementu, kt�ry zostanie dodany
    void append(T const& element);

    /// \brief Czysto wirtualna metoda, kt�ra wstawia element w podane miejsce
    /// 
    /// \param n - miejsce, w kt�re zostanie wstawiony element
    /// \param element - referencja do elementu, kt�ry zostanie wstawiony
    /// \return metoda zwraca:
    /// \li true - gdy uda si� wstawi� element
    /// \li false - gdy nie uda si� wstawi� elementu
    virtual bool insert(int n, T const& element) = 0;

    /// \brief Metoda podmienia element o podanym indeksie nowym elementem
    /// 
    /// \param n - indeks podmienianego elementu
    /// \param element - referencja do nowego elementu
    /// \return zwraca:
    /// \li true - gdy uda si� podmieni� element
    /// \li false - gdy nie uda si� podmieni� elementu
    bool replace(int n, T const& element);

    /// \brief Czysto wirtualna metoda, kt�ra zwraca warto�� elementu
    ///
    /// \param n - indeks zwracanego elementu
    virtual T& at(int n) const = 0;

    /// \brief Czysto wirtualna metoda, kt�ra zwraca ilo�� element�w w pojemniku
    ///
    /// \return zwraca ilo�� element�w element�w
    virtual int size(void) const = 0;

    /// \brief Czysto wirtualna metoda, kt�ra usuwa wybrany element
    ///
    /// \param n - indeks usuwanego elementu
    /// \return zwraca:
    /// \li true - gdy uda si� usun�� element
    /// \li false - gdy nie uda si� usun�� elementu
    virtual bool remove(int n) = 0;

    /// \brief Metoda opr�nia pojemnik
    void clear(void);

    /// \brief Metoda sprawdza, czy pojemnik jest pusty
    ///
    /// \return zwraca:
    /// \li true - gdy pojemnik jest pusty
    /// \li false - gdy pojemnik nie jest pusty
    bool isEmpty(void);

    /// \brief Metoda wyszukuje element w pojemniku przez warto�� od zadanego momentu
    ///
    /// \param _value - warto�� szukanego elementu
    /// \param _from - wskazany moment pocz�tkowy, domy�lnie 0 (pocz�tek)
    /// \return zwraca:
    /// \li indeks elementu - gdy element zostanie znaleziony
    /// \li -1 - gdy element nie zostanie znaleziony
    int indexOf(T const& _value, int _from = 0) const;

    /// \brief Metoda sprawdza, czy podany element ju� jest w pojemniku, szuka przez warto�� od zadanego momentu
    ///
    /// \param _value - warto�� szukanego elementu
    /// \param _from - wskazany moment pocz�tkowy, domy�lnie 0 (pocz�tek)
    /// \return zwraca:
    /// \li true - gdy element zostanie znaleziony
    /// \li false - gdy element nie zostanie znaleziony
    bool contains(T const& _value, int _from = 0) const;

    /// \brief Wirtualne prze�adowanie operatora przypisania "="
    ///
    /// \param right - referencja do obiektu macierzystego
    /// \return zwraca referencj� do obiektu macierzystego
    aghContainer<T>& operator=(aghContainer<T> const& right);

    /// \brief Prze�adowanie operatora por�wnania "=="
    ///
    /// \param right - referencja do obiektu z kt�rym por�wnujemy
    /// \return zwraca:
    /// \li true - gdy zawarto�� pojemnik�w jest taka sama
    /// \li false - gdy zawarto�� pojemnik�w nie jest taka sama
    bool operator==(aghContainer<T> const& right);

    /// \brief Prze�adowanie operatora nier�wno�ci "!="
    ///
    /// \param right - referencja do obiektu z kt�rym por�wnujemy
    /// \return zwraca:
    /// \li true - gdy zawarto�� pojemnik�w nie jest taka sama
    /// \li false - gdy zawarto�� pojemnik�w jest taka sama
    bool operator!=(aghContainer<T> const& right);

    /// \brief Prze�adowanie operatora "[]", zwraca ��dany element
    ///
    /// \param - indeks zwracanego elementu
    /// \return zwraca referencj� do ��danego elementu
    T& operator[](int n) const;

    /// \brief Prze�adowanie operatora "+=", dopisuje wszystkie elementy z pojemnika right
    ///
    /// \param right - referencja do obiektu z kt�rego metoda pobiera nowe elementy
    /// \return zwraca referencj� do this
    aghContainer<T>& operator+=(aghContainer<T> const& right);

    /// \brief Prze�adowanie operatora "+=", dodaje element do pojemnika
    ///
    /// \param element - referencja do dodawanego elementu
    /// \return zwraca referencj� do this
    aghContainer<T>& operator+=(T const& element);

    /// \brief Prze�adowanie operatora "<<", dodaje element do pojemnika
    ///
    /// \param element - referencja do dodawanego elementu
    /// \return zwraca referencj� do this
    aghContainer<T>& operator<<(T const& element);

    /// \brief Prze�adowanie operatora "<<", dopisuje wszystkie elementy z pojemnika right
    ///
    /// \param right - referencja do obiektu, z kt�rego metoda pobiera nowe elementy
    /// \return zwraca referencj� do this
    aghContainer<T>& operator<<(aghContainer<T> const& right);

    /// \brief Metoda zaprzyja�niona. Prze�adowanie operatora ">>", wypisuje zawarto�� pojemnika na strumie�
    ///
    /// \param output - referencja do strumienia, na kt�ry zostanie wypisany pojemnik
    /// \param right - referencja do obiektu, kt�rego elementy zostan� wypisane
    /// \return zwraca referencj� do strumienia output
    friend ostream& operator<<(ostream& output, aghContainer<T> const& right)
    {
        for (int i = 0; i < right.size(); ++i)
        {
            output << right.at(i) << "\n";
        }
        return output;
    }
};
// -----------------------------------------------------------------------------

// Definicje metod
// -----------------------------------------------------------------------------

template <class T>
bool aghContainer<T>::invalidIndex(int n) const
{
    if (n >= this->size() || n < 0)
        return true;
    else
        return false;
}
// -----------------------------------------------------------------------------

template <class T>
aghContainer<T>::aghContainer(void)
{
}
// -----------------------------------------------------------------------------

template <class T>
aghContainer<T>::~aghContainer(void)
{
}
// -----------------------------------------------------------------------------

template <class T>
void aghContainer<T>::append(T const& element)
{
    this->insert(this->size(), element);
}
// -----------------------------------------------------------------------------

template <class T>
bool aghContainer<T>::replace(int n, T const& element)
{
    if (this->remove(n))
    {
        this->insert(n, element);
        return true;
    }
    else
        return false;
}
// -----------------------------------------------------------------------------

template <class T>
void aghContainer<T>::clear()
{
    for (int i = this->size() - 1; i > -1; --i)
        this->remove(i);
}
// -----------------------------------------------------------------------------

template <class T>
bool aghContainer<T>::isEmpty(void)
{
    if (this->size() == 0)
        return true;
    else
        return false;
}
// -----------------------------------------------------------------------------

template <class T>
int aghContainer<T>::indexOf(T const& _value, int _from) const
{
    if (this->invalidIndex(_from))
        throw aghException(0, "Index out of range", __FILE__, __LINE__);

    for (int i = _from; i < this->size(); ++i)
    {
        if (this->at(i) == _value)
            return i;
    }

    return -1;
}
// -----------------------------------------------------------------------------

template <class T>
bool aghContainer<T>::contains(T const& _value, int _from) const
{
    if (this->indexOf(_value) == -1)
        return false;
    return true;
}
// -----------------------------------------------------------------------------

template <class T>
aghContainer<T>& aghContainer<T>::operator=(aghContainer<T> const& right)
{
    if (*this == right)
        return *this;
    this->clear();
    for (int i = 0; i < right.size(); ++i)
        this->append(right.at(i));
    return *this;
}
// ------------------------------------------------------------------------------

template <class T>
bool aghContainer<T>::operator==(aghContainer<T> const& right)
{
    if (this->size() != right.size())
        return false;
    for (int i = 0; i < this->size(); ++i)
    {
        if (this->at(i) != right.at(i))
            return false;
    }
    return true;
}
// -----------------------------------------------------------------------------

template <class T>
bool aghContainer<T>::operator!=(aghContainer<T> const& right)
{
    return !(this->operator==(right));
}
// -----------------------------------------------------------------------------

template <class T>
T& aghContainer<T>::operator[](int n) const
{
    if (this->invalidIndex(n))
        throw aghException(0, "Index out of range", __FILE__, __LINE__);
    return this->at(n);
}
// -----------------------------------------------------------------------------

template <class T>
aghContainer<T>& aghContainer<T>::operator+=(aghContainer<T> const& right)
{
    for (int i = 0; i < right.size(); ++i)
        this->append(right.at(i));
    return *this;
}
// -----------------------------------------------------------------------------

template <class T>
aghContainer<T>& aghContainer<T>::operator+=(T const& element)
{
    this->append(element);
    return *this;
}
// -----------------------------------------------------------------------------

template <class T>
aghContainer<T>& aghContainer<T>::operator<<(T const& element)
{
    return this->operator+=(element);
}
// -----------------------------------------------------------------------------


template <class T>
aghContainer<T>& aghContainer<T>::operator<<(aghContainer<T> const& right)
{
    return this->operator+=(right);
}
// -----------------------------------------------------------------------------

#endif

