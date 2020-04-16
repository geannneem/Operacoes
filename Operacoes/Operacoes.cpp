#include <stdio.h>
#include <stdlib.h>

#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>
#include<opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
    cv::Mat image1;
    cv::Mat image2;
    cv::Mat  somaDireta, somaAcumulada,somaSaturada ,somaPonderada, somaEscalar;
    cv::Mat  subDireta, subSaturada, multSaturada, divisaoSaturada;


    image1 = cv::imread("img2-flower.jpg");
    image2 = cv::imread("img1-shoes.jpg");


    std::string SomaDireta = "Soma com operador +";
    somaDireta = image1 + image2;
    subDireta = image1-image2;

    //cv::imwrite("SomaDireta.jpg", somaDireta);
    //cv::imwrite("SubtracaoDireta.jpg", subDireta);
 

    if (image1.empty() || image2.empty())
    {

    }
    //cv::namedWindow(SomaDireta);
    //cv::imshow(SomaDireta, soma);

    std::string SomaSaturada = "Soma com comando add";
    cv::add(image1, image2, somaSaturada);
    cv::subtract(image1, image2, subSaturada);
    cv::multiply(image1, image2, multSaturada);
    cv::divide(image1, image2, divisaoSaturada);

    //cv::namedWindow(SomaSaturada);
    //cv::imshow(SomaSaturada, result2); 
    cv::imwrite("SomaSaturada.jpg", somaSaturada);
    cv::imwrite("SubtracaoSaturada.jpg", subSaturada);
    cv::imwrite("MultiplicacaoSaturada.jpg", multSaturada);
    cv::imwrite("DivisaoSaturada.jpg", divisaoSaturada);

    
    std::string SomaPonderada= "Soma ponderada de imagens";

    double alpha =0.3, beta=0.7, gamma=0;

    cv::addWeighted(image1, alpha, image2, beta, gamma, somaPonderada);

    //cv::namedWindow(SomaPonderada);
    //cv::imshow(SomaPonderada, result3);
    //cv::imwrite("SomaPonderada.jpg", somaPonderada);

    std::string SomaEscalar = "Soma escalar de imagens";
    double escala = 0.3;
    cv::scaleAdd(image1, escala, image2, somaEscalar);
   

    //cv::namedWindow(SomaEscalar);
    //cv::imshow(SomaEscalar, result4);
    //cv::imwrite("SomaEscalar.jpg", somaEscalar);
    
    
    cv::waitKey(0);
    cv::destroyAllWindows();
    return 0;
}

