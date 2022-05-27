# Vector klasės implementacija
### Programa skirta palyginti `std::vector` ir mano sukurtos `MyVector` klasės spartą

## Greičio palyginimas
`std::vector greicio skaiciavimo kodas`
```
vector<int> v1;
auto start = high_resolution_clock::now();
auto stop = high_resolution_clock::now();
duration<double> laikas = stop - start;
for (int sz = 10000; sz <= 100000000; sz *= 10)
{
  start = high_resolution_clock::now();
  for (int i = 1; i <= sz; ++i)
      v1.push_back(i);
  stop = high_resolution_clock::now();
  laikas = stop - start;
  cout << sz << " std::vector: " << laikas.count() << endl;
}
```

`MyVector greicio skaiciavimo kodas`
```
MyVector<int> v2;
for (int sz = 10000; sz <= 100000000; sz *= 10)
{
  start = high_resolution_clock::now();
  for (int i = 1; i <= sz; ++i)
    v1.push_back(i);
  stop = high_resolution_clock::now();
  laikas = stop - start;
  cout << sz << " Mano vektorius: " << laikas.count() << endl;
}
```
`Rezultatai:`

![image](https://user-images.githubusercontent.com/43725384/170757140-1ebedc14-2e1e-4678-92b9-8e8975ddced0.png)
![image](https://user-images.githubusercontent.com/43725384/170757846-a52d396d-11b8-4a81-ae3f-6a768f6c43ac.png)

## front() funkcija
### Funkcija gražinanti pirmą reikšmę
`Implementacija`
```
T& front()
{
  return arr[0];
}
```
`Testavimo kodas`
```
MyVector<int> test;
test.push_back(1);
test.push_back(2);
test.push_back(3);

cout << "Pirmas elementas: " << test.front() << endl << endl;
```
`Rezultatas:`
```
Pirmas elementas: 1
```

## shrink_to_fit() funkcija
### Funkcija optimizuojanti vektoriaus talpą
`Implementacija`
```
void shrink_to_fit()
{
  capacity = current;
  T* newarr = new T[capacity];
  for (int i = 0; i < capacity; i++)
  {
    newarr[i] = arr[i];
  }
  delete[] arr;
  arr = newarr;
}
```
`Testavimo kodas`
```
MyVector<int> test2;
test2.push_back(1);
test2.push_back(2);
test2.push_back(3);

cout << "Capacity pries Shrink_To_Fit: " << test2.getcapacity() << endl;

test2.shrink_to_fit();
cout << "Capacity po Shrink_To_Fit: " << test2.getcapacity() << endl;
```
`Rezultatas:`
```
Capacity pries Shrink_To_Fit: 4
Capacity po Shrink_To_Fit: 3
```
## operator=
### Operatorius sulyginantis du `MyVector`
`Implementacija`
```
MyVector& operator =(const MyVector& rhs)
{
  if (rhs.current > current)
  {
    delete[] arr;
    capacity = rhs.current + 5;
    arr = new int[capacity];
  }
  for (int i = 0; i < rhs.current; i++)
  {
    arr[i] = rhs.arr[i];
  }

  current = rhs.current;

  return *this;
}
```
`Testavimo kodas`
```
MyVector<int> test3;
MyVector<int> copy;
test3.push_back(1);
test3.push_back(2);
copy = test3;
cout << "Copy elementai: ";
copy.print();
```
`Rezultatas:`
```
Copy elementai: 1 2
```
## erase() funkcija
### Funkcija ištrinanti norimą reikšmę
`Implementacija`
```
void erase(int index)
{
  for (int i = index; i < current - 1; i++)
  {
    arr[i] = arr[i + 1];
  }
  current--;
}
```
`Testavimo kodas`
```
MyVector<int> test4;
test4.push_back(1);
test4.push_back(2);
test4.push_back(3);
cout << "Pradiniai elementai: ";
test4.print();

test4.erase(1);
cout << "Elementai po trynimo: ";
test4.print();
```
`Rezultatas:`
```
Pradiniai elementai: 1 2 3
Elementai po trynimo: 1 3
```
## pop_back() funkcija
### Funkcija ištrinanti paskutinę reikšmę
`Implementacija`
```
void pop_back()
{ 
  current--;
} 
```
`Testavimo kodas`
```
MyVector<int> test5;
test5.push_back(1);
test5.push_back(2);
test5.push_back(3);
cout << "Pradiniai elementai: ";
test5.print();

test5.pop_back();
cout << "Elementai po pop_back: ";
test5.print();
```
`Rezultatas:`
```
Pradiniai elementai: 1 2 3
Elementai po pop_back: 1 2
```
