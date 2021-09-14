# mnist-neural-network
*mnist-neural-network* implements a neural network to recognize handwritten digits. 
I used [MNIST database](http://yann.lecun.com/exdb/mnist/) to train the network.
手写数据集的神经网络 用mnist数据集
# Installation and usage
We can use *make* utility to install the software:
```sh
$ cd implementation && make
```

after the installation, we can execute the software:

```sh
$ ./mnn_main --help
```

the helper has this form:

```
Usage: ./mnn_main [Options]

Options:
   --help                               Print this help打印帮助
   --config-file <file>                 Specify config file to load加载配置文件，如果不加在则默认这个
                                            (if you don't specify this option, 
                                            "default_configuration.conf" will be loaded)
   --load-parameters <file>             Load weights and biases contained in the file加载权重和偏好
                                            (you must use '--save-parameters' option in a previous execution)
   --save-parameters <file>             Save weights and biases in the file保存权重和偏好
   --image <file>                       Predict number of the image预测的图片
                                            (file's name and its content must respect some constrains)
   --train                              Train the neural network练习神经网络
                                            (if you use "--save-parameters", this option will be implicit)
   --show-image <file>                  Show specified image现实一个图片细节
   --export-parameters <file>           Save weights and biases as matrices and arrays 
                                            in the file with Javascript syntax
                                                        以矩阵或行列式形式保存权重和偏好（Javascript 语法）
```

# Config file

Before executing the neural network, we can modify the config file. 
It contains the hyperparameters of the network. The default configuration looks like:

```javascript
{
    hidden-layers: 20;
    epochs: 30;
    learning-rate: 3;
    mini-batches: 10;
};
```

*implementation/default_configuration.conf* file contains all information about parameters and the values that they can assume (for example *hidden-layers* could be an array).


# Execution

This video illustrates a typical execution of the software. Since training can require several times to terminate every epoch, we assume that we had already trained the network using *--save-parameters* option for saving the parameters inside *params_1.txt*. Moreover, this option will execute the training automatically as we had specified in the helper:

```sh
$ ./mnn_main --save-parameters data/output/params_1.txt
```

is equal to:

```sh
$ ./mnn_main --save-parameters data/output/params_1.txt --train
```

[![asciicast](https://asciinema.org/a/8aote8a6c536czbvgbls1971g.png)](https://asciinema.org/a/8aote8a6c536czbvgbls1971g)

# Tools
I created a set of tools to handle images. All of them, except *extract_test_information_from_mnist_db.c*, require OpenCV library.

# Other information

- if you modify the configuration file and, for some reason, it will be incorrect, you can enable debug uncommenting line 16 at *mnn_parser_config_file.h* file to check the error;
- if you want to speed up the training, you can decrease the number of training and number of tests (at the end of each epoch, the program will check the number of correct prediction on 10.000 images). It's enough to modify constants *N_TRAINING_IMAGES* and *N_TEST_IMAGES* (file *mnn_config.h* line 11 and line 14).
