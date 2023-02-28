## strcpy()
'
if (dest == NULL) {
    return NULL;
}
'

不知道為何要加這段，
如果dest未被分配到在傳進function時就會報錯。

-----

'char* ptr = dict;' 和 'return ptr;'，
dict隨迴圈移動到最後一項，
須回傳&dict[0]於main()。

-----

'*dest++' 和
 '*(dest++)' 同意，
都是先操作完 *dest 後，再移動 *dest位置。

-----

function name用 'void' 搭配 'return ;' 也可以，
如下:
'
void strcpy(char* dict, const char* src) {
    while (*src != '\0')
        *dict++ = *src++;

    *dict = '\0';

    return ;
}

int main() {
    char dict[25];
    char src[] = "Hello word.";

	strcpy(dict, src);
    printf("%s\n", dict);

    return 0;
}
'

-----


## strcmp()
功用不是比字串長度是大小，
根據ASCII規則，
小寫字母 > 大寫字母，
字母 > 空格。


## strncmp()


## memset()
function name用 'void' 搭配 'return ;' 也可以，
用 'void*' 是配合C的function寫法。

-----

變數 'str' 使用 'void*' 是配合C的function寫法，
用意何在不清楚，用 'char*' ，
省掉 'char* ptr = (char*) str;' 一樣可以執行。

-----

變數 'c' 也可以使用 'char' 代替 'int'。

-----

變數 'n' 使用 'size_t' 是為了確保傳入的值為正。

-----

'char* ptr = (char*) str;'，
網路上實作的方法都是強制轉成unsigned char*，如下:
'unsigned char* ptr = (unsigned char*) str;' ，
但原因不明。

-----
