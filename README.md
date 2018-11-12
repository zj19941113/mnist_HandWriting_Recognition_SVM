# mnist_HandWriting_Recognition_SVM  
## 数据处理 
在OpenCV的安装路径下，搜索digits，可以得到一张图片，图片大小为1000* 2000，有0-9的10个数字，每5行为一个数字，总共50行，共有5000个手写数字，每个数字块大小为20* 20  

运行data_get.cpp
>g++ data_get.cpp `pkg-config --cflags --libs opencv` -o data_get  
>./ data_get  

![](https://github.com/zj19941113/mnist_HandWriting_Recognition_SVM/blob/master/img/data_get.png)  
注：需提前在data文件夹下新建0~9文件夹  
将每个数字里的400张图放入train_image中对应数字的文件夹，100张放test_image

## 模型训练
运行data_get.cpp  
>g++ svm_train.cpp `pkg-config --cflags --libs opencv` -o svm_train  
>./ svm_train  

## svm分类器测试
运行data_get.cpp  
>g++ svm_test.cpp `pkg-config --cflags --libs opencv` -o svm_test  
>./ svm_test  
![](https://github.com/zj19941113/mnist_HandWriting_Recognition_SVM/blob/master/img/result.png)  
