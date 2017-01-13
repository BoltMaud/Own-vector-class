#include <iostream>
#include <vector>
#include <fstream>

template <typename T, size_t taille>
class TabIterator{
					public:
					  TabIterator( T * p):iterator(p){}
					  
					  T& operator *() {
						  return *iterator;} 
						  
						  
					  T* operator  ++(){
						  return iterator++;
						  } 
						  
					  bool operator ==(const TabIterator &p){
						return iterator==p.iterator;
					  }
					  bool operator !=(const TabIterator &p){
						return iterator!=p.iterator;
					  }
					private:
						T* iterator;

				};



template <typename T, size_t taille>
class Tableau {
        private:
                unsigned int capacite;
                unsigned int NbEl;
                T* tab;
                
                const static int alloc_const=taille;
        public:
				typedef TabIterator<T,taille> iterator ;

				//----------------------------------------------------
				//constructeur vide, juste la taille 
                Tableau(const size_t &s):capacite(s),NbEl(0){
					 unsigned int tab_alloc=alloc_const;
						//tant que la taille demandé est superieur à la taille qu'on veut alloue
						while(s>tab_alloc){
							//on augmente la taille
							tab_alloc+=alloc_const;
						}
						tab =new T[tab_alloc];
						capacite=tab_alloc;
						
                }
                //----------------------------------------------------
				//constructeur classique
                Tableau(const T * t, const size_t &NbE){
					unsigned int tab_alloc=alloc_const;
					//tant que la taille voulu n'est pas assez grande
					while(tab_alloc<sizeof(T)*NbE){
							tab_alloc+=alloc_const;
					}
					//bonne taille nouveau tableau
					tab=new T[tab_alloc];
					capacite=tab_alloc;
					NbEl=NbE;
					//tab=t;
					
					//là on peut utiliser copy non ?
					for(unsigned int i = 0; i < NbE; i++)
					{
						tab[i] = t[i];
					}
					
				} 
				//fonction qui aggrandit la taille et copy tab
				void resize(const size_t &taille_souhaite){
					std::cout << "on est bien rentré dans le resize" ;
					
					//si on a pas la place 
					if(capacite<taille_souhaite){
						std::cout << "la taille était trop petite";

						//on aggrandit capacite
						unsigned int size_alloc=capacite;
						while(size_alloc < taille_souhaite){
							size_alloc+=alloc_const;
						}
						capacite=size_alloc;
						
						
						//on cree un tableau temp
						std::cout << " taille alloue"<<size_alloc;
						T* temp=new T[size_alloc];
						
						//on copie
						for( unsigned int i=0;i < NbEl; i++){
							temp[i] = tab[i];
						}
						delete tab;
						tab=temp;
											
				}
			} 
				//------------------------------------------------
				void ajouter(const T &t){
					std::cout << NbEl << " " << capacite<< " "<< sizeof(T)*2;
					if(!(capacite>(NbEl*sizeof(T)))){
						resize(sizeof(T)*(NbEl+1));
					}
					tab[NbEl]=t;
					NbEl++;
				}
                //------------------------------------------------
                const int getNbEl(){
					return NbEl;
				}
				//------------------------------------------------
				T & operator [](const int &i){
					std::cout << "tab[i]=";
					std::cout << tab[i];
					return tab[i];
				}
				const T operator =(const T &v){
					return v;
				}
				Tableau (const Tableau &t){
					NbEl=t.NbEl;
					capacite=t.capacite;
					tab=new T[t.capacite];
					//on copie
					for( unsigned int i=0;i < t.NbEl; i++){
							tab[i] = t.tab[i];
					}
				}
				~Tableau(){
					delete tab;
				}
				iterator begin(){
					return &(tab[0]);
				}
				iterator end(){
					return &(tab[NbEl]);
				}
        

};

int main(){
	int toto[4]={0,2,6,7};
	Tableau<int,6> A(toto,4);
Tableau<int,6>::iterator it=A.begin();
Tableau<int,6>::iterator ite=A.end();
for(  ;it!=ite;++it)
std::cout << *it << std::endl;
	
	
}
