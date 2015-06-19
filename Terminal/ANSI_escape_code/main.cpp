#include <QCoreApplication>
#include <QTextStream>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QTextStream out(stdout);

    out << "Normal" << endl;

    out << "\x1b[30mBlack\x1b[30m" << endl;
    out << "\x1b[31mRed\x1b[30m" << endl;
    out << "\x1b[32mGreen\x1b[30m" << endl;
    out << "\x1b[33mYellow\x1b[30m" << endl;
    out << "\x1b[34mBlue\x1b[30m" << endl;
    out << "\x1b[35mMagneta\x1b[30m" << endl;
    out << "\x1b[36mCyan\x1b[30m" << endl;
    out << "\x1b[37mWhite\x1b[30m" << endl;

    out << "\x1b[30;1mBlack Bold\x1b[30;0m" << endl;
    out << "\x1b[31;1mRed Bold\x1b[30;0m" << endl;
    out << "\x1b[32;1mGreen Bold\x1b[30;0m" << endl;
    out << "\x1b[33;1mYellow Bold\x1b[30;0m" << endl;
    out << "\x1b[34;1mBlue Bold\x1b[30;0m" << endl;
    out << "\x1b[35;1mMagneta Bold\x1b[30;0m" << endl;
    out << "\x1b[36;1mCyan Bold\x1b[30;0m" << endl;
    out << "\x1b[37;1mWhite Bold\x1b[30;0m" << endl;

    out << "\x1b[30;2mBlack Faint\x1b[30;0m" << endl;
    out << "\x1b[31;2mRed Faint\x1b[30;0m" << endl;
    out << "\x1b[32;2mGreen Faint\x1b[30;0m" << endl;
    out << "\x1b[33;2mYellow Faint\x1b[30;0m" << endl;
    out << "\x1b[34;2mBlue Faint\x1b[30;0m" << endl;
    out << "\x1b[35;2mMagneta Faint\x1b[30;0m" << endl;
    out << "\x1b[36;2mCyan Faint\x1b[30;0m" << endl;
    out << "\x1b[37;2mWhite Faint\x1b[30;0m" << endl;

    out << "\x1b[30;3mBlack Italic\x1b[30;0m" << endl;
    out << "\x1b[31;3mRed Italic\x1b[30;0m" << endl;
    out << "\x1b[32;3mGreen Italic\x1b[30;0m" << endl;
    out << "\x1b[33;3mYellow Italic\x1b[30;0m" << endl;
    out << "\x1b[34;3mBlue Italic\x1b[30;0m" << endl;
    out << "\x1b[35;3mMagneta Italic\x1b[30;0m" << endl;
    out << "\x1b[36;3mCyan Italic\x1b[30;0m" << endl;
    out << "\x1b[37;3mWhite Italic\x1b[30;0m" << endl;

    out << "\x1b[30;4mBlack Underline\x1b[30;0m" << endl;
    out << "\x1b[31;4mRed Underline\x1b[30;0m" << endl;
    out << "\x1b[32;4mGreen Underline\x1b[30;0m" << endl;
    out << "\x1b[33;4mYellow Underline\x1b[30;0m" << endl;
    out << "\x1b[34;4mBlue Underline\x1b[30;0m" << endl;
    out << "\x1b[35;4mMagneta Underline\x1b[30;0m" << endl;
    out << "\x1b[36;4mCyan Underline\x1b[30;0m" << endl;
    out << "\x1b[37;4mWhite Underline\x1b[30;0m" << endl;

    out << "\x1b[30;5mBlack Slow Blink\x1b[30;0m" << endl;
    out << "\x1b[31;5mRed Slow Blink\x1b[30;0m" << endl;
    out << "\x1b[32;5mGreen Slow Blink\x1b[30;0m" << endl;
    out << "\x1b[33;5mYellow Slow Blink\x1b[30;0m" << endl;
    out << "\x1b[34;5mBlue Slow Blink\x1b[30;0m" << endl;
    out << "\x1b[35;5mMagneta Slow Blink\x1b[30;0m" << endl;
    out << "\x1b[36;5mCyan Slow Blink\x1b[30;0m" << endl;
    out << "\x1b[37;5mWhite Slow Blink\x1b[30;0m" << endl;

    out << "\x1b[30;6mBlack Fast Blink\x1b[30;0m" << endl;
    out << "\x1b[31;6mRed Fast Blink\x1b[30;0m" << endl;
    out << "\x1b[32;6mGreen Fast Blink\x1b[30;0m" << endl;
    out << "\x1b[33;6mYellow Fast Blink\x1b[30;0m" << endl;
    out << "\x1b[34;6mBlue Fast Blink\x1b[30;0m" << endl;
    out << "\x1b[35;6mMagneta Fast Blink\x1b[30;0m" << endl;
    out << "\x1b[36;6mCyan Fast Blink\x1b[30;0m" << endl;
    out << "\x1b[37;6mWhite Fast Blink\x1b[30;0m" << endl;

    out << "\x1b[39;49mReset Colors" << endl;
    out << "\x1b[0mReset All" << endl;

    out << "10" ;
    out << "\r20" ; // clear current line
    out << "\r30\n" ;

    return 0;
}
