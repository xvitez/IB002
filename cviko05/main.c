#include <stdio.h>
#include <stdlib.h>     /* srand, rand, malloc, free */
#include <time.h>       /* time */
#include <string.h>    /* memset */

/**
 * Vasim ukolem v teto implementacni uloze je naprogramovat zakladni radici
 * algoritmy. Formulace problemu neni vzdy stejna jako je ve sbirce,
 * musite splnit zadani v komentari nad funkci.
 *
 * Povinne jsou pro vas radici algoritmy InsertSort, MergeSort, QuickSort a
 * CountingSort. Zbyle algoritmy presto doporucujeme naimplementovat.
 */

/**
 * Pomocna funkce swap pro vas, bere argumenty pole 'array', ve kterem
 * prohodi prvky na pozicich indexu 'first' a 'second'.
 */
void swap(int *array, int first, int second) {
    int tmp = array[first];
    array[first] = array[second];
    array[second] = tmp;
}

/**
 * Alternativni verze funkce swap, bere bere ukazatele na prvky 'first'
 * a 'second', ktere prohodi.
 */
void swapAlt(int *first, int *second) {
    int tmp = *first;
    *first = *second;
    *second = tmp;
}

/**
 * Razeni vkladanim. V kazdem pruchodu se nasledujici prvek posouva v poli
 * 'array' tak dlouho, dokud nenarazi na mensi prvek, nebo na zacatek.
 * Velikost vstupniho pole je 'size'.
 *
 * TODO: dopsat tuto funkci
 */
void insertSort(int *array, int size) {
    for (int i = 0; i< size - 1; i++){
        int j = i+1;
        int tmp = array[j];
        while (j>0 && tmp < array[j-1]){
            array[j] = array[j-1];
            j--;
        }
        array[j] = tmp;
    }
}

/**
 * Pomocna funkce pro razeni rozdelovanim (QuickSort). Vstupem je pole 'array',
 * ktere v rozsahu indexu 'from' a 'to' mate rozdelit na posloupnost mensich
 * nebo stejnych cisel jako pivot a posloupnost vetsich cisel nez je pivot.
 *
 * Jako pivot vezmete posledni prvek v danem rozsahu.
 *
 * TODO: dopsat tuto funkci
 */
int quickSortPartition(int *array, int from, int to) {
    int piv = array[to];
    int i = from - 1;
    for(int j = from; j < to-1; j++){
        if (array[j] <= piv){
            i++;
            swap(array, array[i], array[j]);
        }
    }
    //swap(array, array[i+1], array[to]);
    return i;
}

/**
 * Razeni rozdelovanim (QuickSort). Zadane pole 'array' v rozsahu indexu
 * 'from' a 'to' rekurzivne seradte. Pouzijte k tomu funkci na rozdeleni
 * posloupnosti kolem pivota.
 *
 * TODO: dopsat tuto funkci
 */
void quickSort(int *array, int from, int to) {
    int temp = 0;
    if (from < to){
        temp = quickSortPartition(array,from,to);

        quickSort(array,from,temp-1);
        quickSort(array,temp,to);
    }
}

/**
 * Slevani pro razeni spojovanim (MergeSort). Zadane pole 'array' obsahuje
 * 2 usporadane posloupnosti v intervalech od 'left' po 'mid' a od 'mid'+1 po
 * 'right'. K spojeni pouzijte pomocne pole 'aux'. Vysledek ulozte v poli 'array'.
 *
 * TODO: dopsat tuto funkci
 */
void merge(int *array, int *aux, int left, int mid, int right) {
    //TODO
}

/**
 * Razeni spojovanim (MergeSort). Seradte zadane pole 'array' v intervalu
 * od indexu 'left' po index 'right'.
 *
 * Pouzijte pomocnou funkci 'merge' a pomocne pole 'aux'. Vysledek ulozte
 * v poli 'array'.
 *
 * TODO: dopsat tuto funkci
 */
void mergeSort(int* array, int* aux, int left, int right) {
    //TODO
}

/**
 * Razeni pocitanim (CountingSort). Seradte zadane pole 'array' s velikosti
 * 'size'. O poli vite, ze se v nem nachazeji pouze hodnoty v intervalu
 * od 'low' po 'hight' (vcetne obou okraju intervalu).
 *
 * TODO: dopsat tuto funkci
 */
void countingSort(int* array, int size, int low, int high) {
    //TODO
}

/*********************************************************************
 * Nasledujici radici algoritmy nejsou povinne, presto je doporucujeme
 * naimplementovat jako cviceni. Nejsou to nejtezsi radici algoritmy,
 * takze je mozna vhodne je v ramci treninku implementovat drive nez
 * zbyle optimalni radici algoritmy.
 */

/**
 * Pomocna funkce pro vyhledani minima v poli pro razeni vyberem (SelectSort).
 * Nalezne nejmensi prvek v poli 'array' v rozsahu od 'from' do 'to'.
 *
 * Nepovinne TODO: dopsat tuto funkci
 */
int minimum(int *array, int from, int to) {
    return -1;
    //Nepovinne TODO
}

/**
 * Seradte pole 'array' o velikosti 'size' pomoci razeni vyberem.
 *
 * Nepovinne TODO: dopsat tuto funkci
 */
void selectSort(int *array, int size) {
    //Nepovinne TODO
}

/**
 * Prihradkove razeni. Seradte pole 'array' o velikosti 'size', pricemz vite,
 * ze pole neobsahuje vetsi pole nez 'maxVal'.
 *
 * Nepovinne TODO: dopsat tuto funkci
 */
void bucketSort(int* array, int size, int maxVal) {
    //Nepovinne TODO
}

//Dale nasleduji kody potrebne k testum, needitujte je

#define ELEMENT_COUNT 10
#define MAX_ELEMENT 50

int *newRandomArray(int size) {
    int *newArray = (int *) malloc(size*sizeof(int));
    for (int i = 0; i < size; ++i) {
        newArray[i] = rand() % MAX_ELEMENT;
    }
    return newArray;
}

int *newRandomArrayFewValues(int size) {
    int *newArray = (int *) malloc(size*sizeof(int));
    for (int i = 0; i < size; ++i) {
        newArray[i] = rand() % ELEMENT_COUNT/3;
    }
    return newArray;
}

int isSorted(int *array, int size) {
    for (int i = 0; i < size - 1; ++i) {
        if(array[i] > array[i+1]) return 0;
    }
    return 1;
}

void printArray(int *array, int size) {
    for (int i = 0; i < size; ++i) {
        printf("%d, ", array[i]);
    }
    printf("\n");
}

void runQuickSort(int *array, int size) {
    quickSort(array, 0, size-1);
}

void runMergeSort(int *array, int size) {
    int *aux = (int *) malloc(size * sizeof(int));
    mergeSort(array, aux, 0, size-1);
    free(aux);
}

void testSort(void (*sort)(int *, int)) {
    printf("Test 1.: jednoprvkove pole [1]: ");
    int array1[1] = {1};
    sort(array1, 1);

    if (array1[0] == 1 && isSorted(array1, 1)) {
        printf("OK\n");
    }
    else {
        printf("NOK, puvodni pole bylo [1] a bylo serazeno,");
        printf(" po volani sortu je vystup: [%d]\n", array1[0]);
    }

    printf("Test 2.: dvouprvkove pole [1,2]: ");
    int array2[2] = {1,2};
    sort(array2, 2);

    if (array2[0] == 1 && array2[1] == 2 && isSorted(array2, 2)) {
        printf("OK\n");
    }
    else {
        printf("NOK, puvodni pole bylo [1,2] a bylo serazeno,");
        printf(" po volani sortu je vystup: [%d,%d]\n", array2[0], array2[1]);
    }

    printf("Test 3.: dvouprvkove pole [2,1]: ");
    int array3[2] = {2,1};
    sort(array3, 2);

    if (array3[0] == 1 && array3[1] == 2 && isSorted(array3, 2)) {
        printf("OK\n");
    }
    else {
        printf("NOK, puvodni pole bylo [2,1],");
        printf(" po volani sortu je vystup: [%d,%d]\n", array3[0], array3[1]);
    }

    printf("Test 4.: serazene pole 10 prvku [1..10]: ");
    int array4[10] = {1,2,3,4,5,6,7,8,9,10};
    sort(array4, 10);

    if (isSorted(array4, 10)) {
        printf("OK\n");
    }
    else {
        printf("NOK, puvodni pole bylo [1,2..10],");
        printf(" po volani sortu je vystup: ");
        printArray(array4, 10);
    }

    printf("Test 5.: neserazene pole: ");
    int *array5 = newRandomArray(ELEMENT_COUNT);
    printArray(array5, ELEMENT_COUNT);
    sort(array5, ELEMENT_COUNT);

    if (isSorted(array5, ELEMENT_COUNT)) {
        printf("OK\n");
    }
    else {
        printf("NOK: po volani sortu je vystup: ");
        printArray(array5, ELEMENT_COUNT);
    }
    free(array5);
}

void testInsertSort() {
    printf("Testy na InsertSort:\n");
    testSort(insertSort);
}

void testPartition() {
    printf("\nTesty na Partition z QuickSortu:\n");
    printf("Test 1.: jednoprvkove pole [1]: ");
    int array1[1] = {1};
    quickSortPartition(array1, 0, 0);

    if (array1[0] == 1) {
        printf("OK\n");
    }
    else {
        printf("NOK, puvodni pole bylo [1],");
        printf(" po volani Partition je vystup: [%d]\n", array1[0]);
    }

    printf("Test 2.: dvouprvkove pole [1,2]: ");
    int array2[2] = {1,2};
    quickSortPartition(array2, 0, 1);

    if (array2[0] == 1 && array2[1] == 2) {
        printf("OK\n");
    }
    else {
        printf("NOK, puvodni pole bylo [1,2],");
        printf(" po volani Partition je vystup: [%d,%d]\n", array2[0], array2[1]);
    }

    printf("Test 3.: dvouprvkove pole [2,1]: ");
    int array3[2] = {2,1};
    quickSortPartition(array3, 0, 1);

    if (array3[0] == 1 && array3[1] == 2) {
        printf("OK\n");
    }
    else {
        printf("NOK, puvodni pole bylo [2,1], vysledek mel byt [1,2],");
        printf(" po volani Partition je vystup: [%d,%d]\n", array3[0], array3[1]);
    }

    printf("Test 4.: desetiprvkove pole [1..10]: ");
    int array4[10] = {1,2,3,4,5,6,7,8,9,10};
    quickSortPartition(array4, 0, 9);

    if (isSorted(array4, 10)) {
        printf("OK\n");
    }
    else {
        printf("NOK, puvodni pole bylo [1..10], vysledek mel byt [1..10],");
        printf(" po volani Partition je vystup: ");
        printArray(array4, 10);
    }
}

void testQuickSort() {
    printf("\nTesty na QuickSort:\n");
    testSort(runQuickSort);
}

void testMerge() {
    printf("\nTesty na Merge z MergeSortu:\n");
    int *aux = (int *) malloc(ELEMENT_COUNT * sizeof(int));

    printf("Test 1.: Merge 2 jednoprvkovych stejnych poli [1] a [1]: ");
    int array1[2] = {1,1};
    merge(array1, aux, 0, 0, 1);

    if (array1[0] == 1 && array1[0] == 1) {
        printf("OK\n");
    }
    else {
        printf("NOK, puvodni pole bylo [1,1],");
        printf(" po volani Merge je vystup: [%d, %d]\n", array1[0], array1[1]);
    }

    printf("Test 2.: Merge 2 jednoprvkovych stejnych poli [1] a [2]: ");
    int array2[2] = {1,2};
    merge(array2, aux, 0, 0, 1);

    if (array2[0] == 1 && array2[1] == 2) {
        printf("OK\n");
    }
    else {
        printf("NOK, puvodni pole bylo [1,2],");
        printf(" po volani Merge je vystup: [%d,%d]\n", array2[0], array2[1]);
    }

    printf("Test 3.: dvouprvkove pole [2,1]: ");
    int array3[2] = {2,1};
    merge(array3, aux, 0, 0, 1);

    if (array3[0] == 1 && array3[1] == 2) {
        printf("OK\n");
    }
    else {
        printf("NOK, puvodni pole bylo [2,1], vysledek mel byt [1,2],");
        printf(" po volani Merge je vystup: [%d,%d]\n", array3[0], array3[1]);
    }

    printf("Test 4.: desetiprvkove pole [1,3,5,7,9,2,4,6,8,10]: ");
    int array4[10] = {1,3,5,7,9,2,4,6,8,10};
    merge(array4, aux, 0, 4, 9);

    if (isSorted(array4, 10)) {
        printf("OK\n");
    }
    else {
        printf("NOK, vysledek mel byt [1..10],");
        printf(" po volani Merge je vystup: ");
        printArray(array4, 10);
    }

    printf("Test 5.: desetiprvkove pole [1,1,2,2,3,1,1,2,3,3]: ");
    int array5[10] = {1,1,2,2,3,1,1,2,3,3};
    merge(array5, aux, 0, 4, 9);

    if (isSorted(array5, 10)) {
        printf("OK\n");
    }
    else {
        printf("NOK, vysledek mel byt [1,1,1,1,2,2,2,3,3,3],");
        printf(" po volani Merge je vystup: ");
        printArray(array5, 10);
    }

    free(aux);
}

void testMergeSort() {
    printf("\nTesty na MergeSort:\n");
    testSort(runMergeSort);
}

void runCountingSort(int *array, int size) {
    countingSort(array, size, 0, MAX_ELEMENT);
}

void testCountingSort() {
    printf("\nTesty na CountingSort:\n");
    testSort(runCountingSort);

    printf("Test 6.: neserazene pole malo hodnot: ");
    int *array = newRandomArrayFewValues(ELEMENT_COUNT);
    printArray(array, ELEMENT_COUNT);
    countingSort(array, ELEMENT_COUNT, 0, ELEMENT_COUNT/3);

    if (isSorted(array, ELEMENT_COUNT)) {
        printf("OK\n");
    }
    else {
        printf("NOK: po volani sortu je vystup: ");
        printArray(array, ELEMENT_COUNT);
    }
    free(array);

    printf("Test 7.: neserazene pole malo posunutych hodnot: ");
    int *array2 = newRandomArrayFewValues(ELEMENT_COUNT);
    for (int i = 0; i < ELEMENT_COUNT; ++i) {
        array2[i] += 20;
    }
    printArray(array2, ELEMENT_COUNT);
    countingSort(array2, ELEMENT_COUNT, 20, 20+ELEMENT_COUNT/3);

    if (isSorted(array2, ELEMENT_COUNT)) {
        printf("OK\n");
    }
    else {
        printf("NOK: po volani sortu je vystup: ");
        printArray(array2, ELEMENT_COUNT);
    }
    free(array2);
}

void testSelectSort() {
    printf("\nTesty na SelectSort:\n");
    testSort(selectSort);
}

void runBucketSort(int *array, int size) {
    bucketSort(array, size, MAX_ELEMENT);
}

void testBucketSort() {
    printf("\nTesty na BucketSort:\n");
    testSort(runBucketSort);

    printf("Test 6.: neserazene pole malo hodnot: ");
    int *array = newRandomArrayFewValues(ELEMENT_COUNT);
    printArray(array, ELEMENT_COUNT);
    countingSort(array, ELEMENT_COUNT, 0, ELEMENT_COUNT/3);

    if (isSorted(array, ELEMENT_COUNT)) {
        printf("OK\n");
    }
    else {
        printf("NOK: po volani sortu je vystup: ");
        printArray(array, ELEMENT_COUNT);
    }
    free(array);
}

int main(void)
{
    testInsertSort();
    testPartition();
    testQuickSort();
    /*testMerge();
    testMergeSort();
    testCountingSort();
    //BONUS
    testSelectSort();
    testBucketSort();
*/
    return 0;
}
