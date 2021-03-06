/* 筛选数组 */

let filterArray = (~f, arr) => 
    arr
    |> ArrayLabels.to_list
    |> ListLabels.filter(~f)
    |> ArrayLabels.of_list;

/* 
    filterArray(x => x > 2, [|1,2,3,4,5|]);
 */

let rec fill = (~element:'a,~length:int) =>
    if(length <= 0){
        [];
    } else{
        [element,...fill(~element,~length=length-1)];
    };

let rec range = (start:int, end_: int) =>
    if(start >= end_){
        [];
    } else{
        [start,...range(start + 1, end_)];
    }

let rec append = (l1:list('a),l2: list('a)) =>
    switch l1 {
        | [] => l2
        | [head,...tail] => [head,...append(tail,l2)]
    };

let rec len = (myList:list('a)) =>
    switch myList {
        | [] => 0
        | [_, ...tail] => 1 + len(tail)
    };

switch myList {
    | [] => 0
    | [head, ...tail] => ...
};


let rec sort = items: list(int) =>
    switch (items) {
    | [] => []
    | [head, ...rest] => insert_item(sort(rest), head)
    };

let rec fact = (x: int) : int =>
    switch (x) {
    | 0 => 1
    | 1 => 1
    | x => x * fact(x - 1)
    };

/* map 函数实现 */
let rec map = f =>
    fun
    | [] => []
    | [a, ...l] => {
        let r = f(a);
        [r, ...map(f,l)];
    };

let rec flatten = 
    fun
    | [] => []
    | [l, ...r] => l @ flatten(r);


/* 获取列表最后一个元素 来自：https://twitter.com/jbrancha/status/1022319631120379904 */
let rec last = (items: list('a)) : 'a =>
    switch (items) {
    | [] => failwith("The list is empty")
    | [first] => first
    | [_first, ...rest] => last(rest)
    };

let rec insert_item = (items: list(int), item:int) =>
    switch (items) {
    | [] => [items]
    | [head, ...rest] when item < head => [item, head, ...rest]
    | [head, ...rest] when item > head =>
        let sorted_rest = insert_item(rest, item);
        [head, ...sorted_rest];
    };


let print_list = (items: list(int)) => {
    print_char('[');

    let len = List.length(items);
    let print_list_internals = 
        List.iteri((index, item) => {
            print_int(item);
            if (index != len - 1) {
                print_string(", ");
            };
        });
    
    print_list_internals(items);
    print_char(']');
    print_newline();
}


let shuffle = (items: list('a)) => {
    Random.init(int_of_float(Unix.time()));

    let len = List.length(items);
    let boxed_items = ref(items);

    for (i in len - 1 downto 1) {
        let j = Random.int(i);
        boxed_items := swap(boxed_items^, i, j);
    };

    boxed_items^;
}

let items = [1,2,3,4,5,6,7,8,9];

print_list(shuffle(items));s
