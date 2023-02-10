#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main(int argc, char** argv) {
    // Carrega a imagem
    Mat image = imread("image.jpg");
    
    // Verifica se a imagem foi carregada corretamente
    if (!image.data) {
        cout << "Erro ao carregar imagem." << endl;
        return -1;
    }
    
    // Converte a imagem para escala de cinza
    Mat gray;
    cvtColor(image, gray, COLOR_BGR2GRAY);
    
    // Aplica o filtro de borda de Canny
    Mat edges;
    Canny(gray, edges, 50, 150);
    
    // Exibe a imagem original e a imagem processada
    namedWindow("Imagem original", WINDOW_NORMAL);
    imshow("Imagem original", image);
    namedWindow("Bordas", WINDOW_NORMAL);
    imshow("Bordas", edges);
    
    waitKey(0);
    return 0;
}
