# CPP_MPLA

## 說明
![image](https://github.com/leodflag/CPP_Multicategory-Classification_PLA/blob/master/img/Description1.png)
![image](https://github.com/leodflag/CPP_Multicategory-Classification_PLA/blob/master/img/Description2.png)

## 虛擬碼
    1. 從csv檔取得資料
    2. 初始化決策函數權重矩陣與資料矩陣
    3. 將類別資料代入所有決策函數，計算出所有數值
    4. 比較所有數值，找出最大值
    5. 判斷最大值陣列位置是否與相應類別相符
        a. 若相符，權重無須調整，分類器正確數量加一
        b. 若判別錯誤，將相應類別的決策函數加上類別資料數值，其他類別的決策函數則減掉類別資料數值
    6. 重複3到5，直到所有分類器皆正確，則跳出迴圈
    7. 印出分類器各自權重
    
## 結果
data <br>
3,3 <br>
0,0,1 <br>
1,1,1 <br>
-1,1,1  <br>
![image](https://github.com/leodflag/CPP_Multicategory-Classification_PLA/blob/master/img/data_result_weight.png)

data1 <br>
3,3 <br>
2,4,1 <br>
4,1,1 <br>
-1,-1,1 <br>
![image](https://github.com/leodflag/CPP_Multicategory-Classification_PLA/blob/master/img/data1_result_weight.png)

data2 <br>
4,3 <br>
0,1,1 <br>
1,1,1 <br>
1,-2,1 <br>
-1,0,1 <br>
![image](https://github.com/leodflag/CPP_Multicategory-Classification_PLA/blob/master/img/data1_result_weight.png)

## 文章
![image](https://github.com/leodflag/CPP_Multicategory-Classification_PLA/blob/master/img/Q1.jpg)
![image](https://github.com/leodflag/CPP_Multicategory-Classification_PLA/blob/master/img/Q2.jpg)
![image](https://github.com/leodflag/CPP_Multicategory-Classification_PLA/blob/master/img/Q3.jpg)
![image](https://github.com/leodflag/CPP_Multicategory-Classification_PLA/blob/master/img/Q4.jpg)
