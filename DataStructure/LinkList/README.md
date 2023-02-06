LinkkedList_Basic.c
單純用Node創Linked List。
用pointer新增node。

===================

LinkkedList_Operation.c
較複雜的指標寫法，
有push跟append。

===================

LinkkedList_Operation_2.c
最簡潔的做法。
https://www.geeksforgeeks.org/insertion-in-linked-list/?ref=lbp

push時因為要把原Linked list的第一個以新的Node取代，
因此傳入function裡的參數要是Node*的pointer(Node**)，
才能在function真的改到值，
而非複製一份，
故使用struct Node** node作為傳入push function的參數，KL
可以在push function加入
    printf("\n ---Created Linked list is: ");
    printList(node);
與main function裡的這兩行做比較，
底下為止複製到function未改到值的例子。

void push(struct Node* node, int data) {
	struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));

	new_node -> data = data;
	new_node -> next = node;

	node = new_node;

    printf("\n ---Created Linked list is: ");
    printList(node);
}

===================

struct為自定義的組合型資料型態，
c語言無法在宣告此變數的同時判斷應分配的記憶體大小，
在使用時須使用data = (struct var*) malloc(sizeof(struct var));
來手動分配記憶體位置。

===================

簡單來說，要改到Node*的address時才會用到Node**，
LinkkedList_Operation_2.c中，
push的作法是將原"node"位置之前新增node，
再將"node"名稱的位址變數(node*)改成新增的node位5址，
因為"node"名稱的位址變數(node*)要還成新增node的位址，
因此要用node**改變node*的內容。
append則是遇到node為空時，
要用跟push一樣的方式新增node的，
因此需要用到node**。

了解上述原理後，
此兩個用到node**的做法，
可以改成以node*實踐，
只要把新的node加在第1個node之後即可，
詳見LinkkedList_Operation_3.c的push跟append，
但此作法在node為NULL時會有問題，
因為沒分配記憶體給NULL的node，
push跟append第一個node時會失敗、
但若於main function內分配記憶體位置時，
即
head = (struct Node*) malloc(sizeof(struct Node));
在push跟append function又會無法判斷
if(node == NULL)
導致執行失敗，
若於push跟append function內分配記憶體位置時，
即
node = (struct Node*) malloc(sizeof(struct Node));
則function結束時，
被分配的位置也會隨之釋放，
只有在push跟append function內call printList 才會成功，
故LinkkedList_Operation_3.c不可使用，
還是只能用LinkkedList_Operation_2.c中Node**的方式
implement push跟append function。

===================

LinkedList_Sort.c
bubbleSort_2 function為更簡潔的寫法，
也可以用do while。

===================

LinkedList_Sort.c
insertionSort將正確位置上的值，
一個一個往後推，
再將正確地從放入正確的位置。

insertionSort_2直接新增一個node，
放入正確的值，
並把正確值的位置 free掉。

其他方法:
https://www.geeksforgeeks.org/insertion-sort-for-singly-linked-list/

===================

===================

===================

===================