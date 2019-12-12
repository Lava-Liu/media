/* ==================================================================
 *       Filename:  main.cpp
 *    Description:  
 *        Created:  2013年11月11日 11时20分31秒
 *       Compiler:  gcc/g++
 *         Author:  Star (Liu Wei), 384439695@qq.com
 *        Company:  昆山杰普科技有限公司
 * ==================================================================*/
#include <QApplication>
#include <QPushButton>

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);
	QPushButton *button = new QPushButton();
	button->setText("button");
	button->show();

	QObject::connect(button, SIGNAL(clicked()),&app, SLOT(quit()) );


	return app.exec();
}
