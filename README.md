# Week-12-

# 数据结构与算法

## 冒泡排序，希尔排序

### 冒泡排序

* 时间复杂度

  * O(N^2)
  * 需要将n-1个元素放入到正确的位置（n），每次找一个元素的位置时都需要遍历后面的所有元素(n)

* 冒泡排序法的改进

  * 一旦在某次循环中发现没有执行交换操作时，就break --》此时数组一定有序了

  * 执行完最后一次交换后，后面的元素都已经有序了

    ```c++
    //设置了一个indicator来当作有序数组的指标
    for (int i = 0; i < arr.size() - 1;) {
    			int indicator = 0;
    			for (int j = i+1; j <= arr.size() - i - 1; ++j) {
    				if (arr[j] > arr[j - 1]) {
    					swap(arr[j], arr[j - 1]);
    					indicator = j + 1;
    				}
    			}
    			if (indicator)
    				break;
    			i = arr.size() - indicator;
    
    ```

    

### 希尔排序

* 逻辑

  * 基于插入排序法
  * 但是不同于插入排序法只处理相邻元素，希尔排序法处理步长元素
  * 非常有利于近乎倒序的数组排序

* 时间复杂度

  * 经过测试，时间复杂度介于O(NlogN)和O(N^2)之间

* 步长 --》如何实现不处理相邻元素的？

  ```c++
  		//将h当作步长，来进行插入排序法
  		int h = arr.size() / 2;
  		while (h >= 1) {
  			for (int start = 0; start < h; ++start) {
  				//对每个{start,start+h...}进行插入排序法
  				for (int i = start + h; i < arr.size(); i += h) {
  					int t = arr[i];
  					int j = i;
  					for (j; j - h >= 0; j -= h) {
  						if (arr[j - h] > arr[j])
  							arr[j] = arr[j - h];
  						else
  							break;
  					}
  					arr[j] = t;
  				}
  			}
  			h /= 2;
  ```

  

## 线段树，Trie和并查集

### 线段树

* 引入线段树的意义
  * 便于区间的查找与更新，例如解决区间染色以及区间查询的问题

* 线段树
  * 线段树是二叉树，但不一定是满二叉树也不是完全二叉树，但是一定是平衡二叉树
  * 平衡二叉树
    * 概念 --》 最深深度与最浅深度的差为1

* 特点
  * 对于线段树来说，既不删除元素也不增加元素。
  * 线段树只是做查询 --》每一个线段树节点存储的都是一个区间的信息
  * 修改元素
  * 可以利用数组实现线段树，且开辟一个大小为2N的静态空间

### Trie

* 用来存储单词

* 也称为字典树或者前缀树

* 时间复杂度为O(w),w为查询英文的长度

* 对于字典树的每一个节点 

  * Map<char,Node> next

  * bool is_word

    * 单靠叶子节点来表示一个单词的结尾是完全不够的

      --》比如panda，a作为叶子节点来表示单词的结束，但是前面的pan也是一个单词，以n作为结束。

      --》 所以每个叶子节点存储一下该节点是否为一个单词的结尾

### 并查集

* 用来处理连接问题（建立a跟b的联系；查找a跟b之间是否有联系）

* 所以并查集的优化主要在is_connected和union上面

* 优化并查集

  * 使用数组表示并查集

    * is_connected --> O(1)
    * union --> O(n)    *每次都要遍历一遍数组，建立联系*

  * 使用树表示并查集

    * 树 --》 由孩子节点去找寻父亲节点
    * 建立两个节点联系的时候其实是将两个节点的根节点联系起来

  * 优化size

    * 加一个数组size,每一次都将size小的加到大的里面去

      ```c++
      	int p_root = find_root(p);
      	int q_root = find_root(q);
      	if (p_root == q_root)return;
      	if (size[p_root] > size[q_root]) {
      		parent[q_root] = p_root;
      		size[p_root] += size[q_root];
      	}
      	else {
      		parent[p_root] = q_root;
      		size[q_root] += size[p_root];
      	}
      ```

      

  * 优化rank

    * size的不足，其实我们是要减少树的深度，增加广度，所以用rank(表达子节点的深度)更加适合

      ```c++
      	int p_root = find_root2(p);
      	int q_root = find_root2(q);
      	if (p_root == q_root)return;
      	if (rank[p_root] > rank[q_root]) 
      		parent[q_root] = p_root;
      	else if (rank[p_root] < rank[q_root]) 
      		parent[p_root] = q_root;
      	else {
      		parent[p_root] = q_root;
      		rank[q_root] += 1;
      	}
      ```

  * 路径压缩1

    * 当出现树完全退化成一个链表的时候，树的深度很深，非常可怕，所以利用path compression来改

    * 在每次find的时候，都将该节点的父亲节点，改成父亲节点的父亲节点，从而减小深度

      ```c++
      int Union_find::find_root(int t) {
      	while (t != parent[t]) {
      		parent[t] = parent[parent[t]];
      		t = parent[t];
      	}
      	return t;
      }
      ```

  * 路径压缩2

    * 进一步优化，让目标节点上面的所有有连接的节点都直接接到目标节点的根节点上去

      --》例如，如果将退化成链表的树进行路径压缩过后就变成了深度为1的树

    * 使用递归的方式实现

      ```c++
      int Union_find2::find_root2(int t) {
      	if (t != parent[t])
      		parent[t] = find_root2(parent[t]);
      	return parent[t];
      }
      ```

      
