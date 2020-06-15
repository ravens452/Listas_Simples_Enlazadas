using namespace std;

class LinkedList {
public:
    int size{};
    Node *head = nullptr;
    Node *final = nullptr;
    LinkedList(){};
    LinkedList(int size, Node *head){
        this->size = size;
        this->head=head;
    };
    ~LinkedList();


    void insert(int );
    void remove(int);
    void print() const;
    void insertarOrdenado(int);

};

void LinkedList::insert(int dato){
    Node* nuevo = new Node(nullptr,dato);
    if (head == nullptr){
        head=nuevo;
            final = nuevo;
            nuevo->elem=dato;
    }else{
        final->next = nuevo;
        final = final->next;}
}

 void LinkedList::remove(int n) {
    cout<<"Se eliminara n = "<<n<<" de la lista"<<endl;
    Node *actual = head;
    Node *anterior = nullptr;
    while (actual->elem !=n && actual->next != nullptr){
        anterior = actual;
        actual=actual->next;
    }
    if (actual->elem != n && actual->next== nullptr)
        cout<<"No se encuentra el valor "<< n<< " en la lista"<<endl;

    else if(anterior== nullptr){ //esta en la primera de la lista
        head = head->next;
        delete actual;
        cout<<"Se elimino el primero de la lista"<<endl;
    }
    else if(actual->next!= nullptr){ //esta en la entrelista
        anterior->next=actual->next;
        delete actual;
        cout<<"Se elimino corectamente 2"<<endl;
    }else if(actual->next == nullptr && actual->elem==n){
        cout<<"Eliminando el ultimo de la fila"<<endl;
        anterior->next=actual->next;
        delete actual;
    }
    else{
            cout<<"es imposible realizar la operacion"<<endl;
    }
}


void LinkedList::print() const {
    cout<<"----------llamada desde el print ---------"<<endl;
    Node *auxiliar;
    auxiliar=head;
    cout<<"La lista completa es: "<<endl;

    while (auxiliar!= nullptr){
        cout<<auxiliar->elem<<"  ";
        auxiliar = auxiliar->next;
    }
    cout<<endl;
}

void LinkedList::insertarOrdenado(int n) {

    Node* nuevo = new Node();
    nuevo->elem = n;
    nuevo->next = nullptr;

    if (head== nullptr || n < head->elem){
        nuevo->next=head;
        head=nuevo;
    }
    else{
        Node *auxiliar = head;
        while (auxiliar->next != nullptr && auxiliar->next->elem < n){
            auxiliar = auxiliar->next;
        }
        if (auxiliar->next != nullptr){
            nuevo->next = auxiliar->next;
        }
        auxiliar->next = nuevo;
    }

}

LinkedList::~LinkedList() {
    cout<<"El destructor ha sido invocado"<<endl;
    Node *p= head;
    while (p){
        p=head->next;
        delete head;
        head=p;
    }
}
