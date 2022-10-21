//Author: Logan Markley
//Class: CS1575
//Semester: Fall 2022
//Due Date: Fri, 10/21/22


using namespace std;

//START - auxiliary functions ----- DONE

template <class T>
void ArrayList<T>::grow()
{
    int newMax = m_max * 2;
    T* tmp = new T[newMax];
    for(int i=0; i<m_size; i++)
    {
        tmp[i] = m_data[i];
    }
    delete [] m_data;
    m_data = tmp;
    tmp = NULL;
    m_max = newMax;
    return;
}

template <class T>
void ArrayList<T>::shrink()
{
    int newMax = m_max / 2;
    T* tmp = new T[newMax];
    for(int i=0; i<m_size; i++)
    {
        tmp[i] = m_data[i];
    }
    delete [] m_data;
    m_data = tmp;
    tmp = NULL;
    m_max = newMax;
    return;
}

//END - auxiliary functions -----



//START - constructors ----- DONE

template <class T>
ArrayList<T>::ArrayList(int s, const T& x)
{
    m_size = s;
    m_max = m_size * 2;
    m_data = new T[m_max];
    for(int i=0; i<m_size; i++)
    {
        m_data[i] = x;
    }
}

//END - constructors -----



//START - big 3 member functions ----- DONE

template <class T>
ArrayList<T>::~ArrayList()
{
    delete [] m_data;
    m_data = NULL;
    m_size = 0;
    m_max = 0;
}

template <class T>
ArrayList<T>& ArrayList<T>::operator=(const ArrayList<T>& rhs)
{
    m_size = rhs.m_size;
    m_max = rhs.m_max;
    delete [] m_data;
    m_data = new T[m_size];
    for(int i=0; i<m_size; i++)
    {
        m_data[i] = rhs.m_data[i];
    }
    return *this;
}

template <class T>
ArrayList<T>::ArrayList(const ArrayList<T>& cpy)
{
    m_size = cpy.m_size;
    m_max = cpy.m_max;
    m_data = new T[m_size];
    *this = cpy;
}

//END - big 3 member functions -----



//START - basic Accessor operations ----- DONE

template <class T>
int ArrayList<T>::size() const
{
    return m_size;
}

template <class T>
const T& ArrayList<T>::first() const
{
    if(m_size == 0) //error trapping
    {
        cout<<"!!! ERROR : PANIC in ARRAYLIST !!!.first()  (List is empty)"<<endl;
        return m_errobj;
    }
    
    return m_data[0];
}

template <class T>
T& ArrayList<T>::operator[](int i)
{
    if(i<0 || i>=m_size) //error trapping
    {
        cout<<"!!! ERROR : PANIC in ARRAYLIST !!!.[]  (index out of bounds)"<<endl;
        return m_errobj;
    }
    
    return m_data[i];
}

template <class T>
const T& ArrayList<T>::operator[](int i) const
{
    if(i<0 || i>=m_size) //error trapping
    {
        cout<<"!!! ERROR : PANIC in ARRAYLIST !!!.[]  (index out of bounds)"<<endl;
        return m_errobj;
    }
    
    return m_data[i];
}

template <class T>
int ArrayList<T>::search(const T& x) const
{
    for(int i=0; i<m_size; i++)
    {
        if( m_data[i] == x )
            return i;
    }
    return -1;
}

//END - basic Accessor operations -----



//START - Basic Mutator Operations ----- DONE

template <class T>
void ArrayList<T>::clear()
{
    delete [] m_data;
    m_size = 0;
    m_max = 4;
    m_data = new T[m_max];
    return;
}

template <class T>
void ArrayList<T>::insert_back(const T& x)
{
    m_data[m_size] = x;
    m_size++;
    if(m_size == m_max)
        grow();
    return;
}

template <class T>
void ArrayList<T>::insert(const T& x, int i)
{
    if(i<0 || i>m_size) //error trapping
    {
        cout<<"!!! ERROR : PANIC in ARRAYLIST !!!.insert()  (index out of bounds)"<<endl;
        return;
    }
    
    int tmpIndex = m_size; //this is all for shifting data to the right one index
    while(tmpIndex>i)
    {
        m_data[tmpIndex] = m_data[tmpIndex-1];
        tmpIndex--;
    }
    m_data[i] = x; //placing x into its index after shifting.
    m_size++;
    if(m_size == m_max)
        grow();
    return;
}

template <class T>
void ArrayList<T>::remove(int i)
{
    if(i<0 || i>=m_size) //error trapping
    {
        cout<<"!!! ERROR : PANIC in ARRAYLIST !!!.remove()  (index out of bounds)"<<endl;
        return;
    }
    
    int tmpIndex = i; //this is all for shifting data to the left one index
    while(tmpIndex<m_size-1)
    {
        m_data[tmpIndex] = m_data[tmpIndex+1];
        tmpIndex++;
    }
    if(m_size > 0)
        m_size--;
    if(m_size < m_max/4)
        shrink();
    return;
}

//END - Basic Mutator Operations -----



//START - Complex Mutator Operations ----- DONE

template <class T>
void ArrayList<T>::swap(int i, int k)
{
    if(i<0 || i>=m_size || k<0 || k>=m_size) //error trapping
    {
        cout<<"!!! ERROR : PANIC in ARRAYLIST !!!.swap()  (index out of bounds)"<<endl;
        return;
    }
    
    T tmp = m_data[i];
    m_data[i] = m_data[k];
    m_data[k] = tmp;
    return;
}

template <class T>
void ArrayList<T>::purge()
{   
    for(int i=0; i<m_size; i++)
    {
        T tmpElement = m_data[i];
        for(int j=i+1; j<m_size; j++)
        {
            if(tmpElement == m_data[j])
            {
                remove(j);
                j--;
            }
        }
    }
    return;
}

template <class T>
void ArrayList<T>::reverse()
{
    for(int i=0; i<m_size/2; i++)
    {
        T tmp = m_data[i];
        m_data[i] = m_data[m_size-1-i];
        m_data[m_size-1-i] = tmp;
    }
    return;
}

//END - Complex Mutator Operation -----
