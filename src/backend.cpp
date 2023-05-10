#include "backend.h"
#include "qdebug.h"

#include <QMap>

namespace AsciiArt {

Backend::Backend(QObject *parent)
    : QObject{parent}
{}

namespace {

struct AsciiChar {
    QString d[6];
};

QMap<QChar, AsciiChar> artCharacters() {
    static QMap<QChar, AsciiChar> chars = {
        {'a', {" _____ ",
               "|  _  |",
               "| |_| |",
               "|  _  |",
               "| | | |",
               "|_| |_|"}
        },
        {'b', {" ____  ",
               "|    \\ ",
               "|  O  |",
               "|    < ",
               "|  O  |",
               "|____/ "}
        },
        {'c', {" ______",
               "| ____|",
               "| |    ",
               "| |    ",
               "| |___ ",
               "|_____|"}
        },
        {'d', {" ____  ",
               "|  _ \\ ",
               "| | | |",
               "| | | |",
               "| |_| |",
               "|____/ "}
        },
        {'e', {" _____ ",
               "|  ___|",
               "| |__  ",
               "|  _|  ",
               "| |___ ",
               "|_____|"}
        },
        {'f', {" _____ ",
              "|  ___|",
              "| |__  ",
              "|  _|  ",
              "| |    ",
              "|_|    "}
        },
        {'g', {" _____ ",
              "|  ___|",
              "| |    ",
              "| |  _ ",
              "| |_| |",
              "|_____|"}
        },
        {'h', {" _   _ ",
              "| | | |",
              "| |_| |",
              "|  _  |",
              "| | | |",
              "|_| |_|"}
        },
        {'i', {"   _   ",
              "  | |  ",
              "  | |  ",
              "  | |  ",
              "  | |  ",
              "  |_|  "}
        },
        {'j', {" _____ ",
               "|___  |",
               "    | |",
               "    | |",
               " ___| |",
               "|____/ "
               }
        },
        {'k', {" _   _ ",
               "| | / /",
               "| |/ / ",
               "|   <  ",
               "| |\\ \\ ",
               "|_| \\_\\"
               }
        },
        {'l', {" _     ",
               "| |    ",
               "| |    ",
               "| |    ",
               "| |___ ",
               "|_____|"
               }
        },
        {'m', {" _   _ ",
               "| \\ / |",
               "|  v  |",
               "| |v| |",
               "| | | |",
               "|_| |_|"
               }
        },
        {'n', {" _   _ ",
               "| \\ | |",
               "|  \\| |",
               "|     |",
               "| |\\  |",
               "|_| \\_|"
               }
        },
        {'o', {" _____ ",
               "|  _  |",
               "| | | |",
               "| | | |",
               "| |_| |",
               "|_____|"
            }
        },
        {'p', {" ____  ",
               "|  _ \\ ",
               "| |_| |",
               "|  __/ ",
               "| |    ",
               "|_|    "
               }
        },
        {'q', {" _____ ",
               "|  _  |",
               "| | | |",
               "| | | |",
               "| |_| /",
               "|___/\\\\"
            }
        },
        {'r', {" ____  ",
               "|  _ \\ ",
               "| |_| |",
               "|    / ",
               "| |\\ \\ ",
               "|_| \\_\\"
               }
        },
        {'s', {" _____ ",
               "/  ___|",
               "| |__  ",
               " \\__ \\ ",
               " __|  |",
               "|____/ "
               }
        },
        {'t', {" _____ ",
               "|_   _|",
               "  | |  ",
               "  | |  ",
               "  | |  ",
               "  |_|  "
               }
        },
        {'u', {" _   _ ",
               "| | | |",
               "| | | |",
               "| | | |",
               "| |_| |",
               "|_____|"
               }
        },
        {'v', {" _   _ ",
               "| | | |",
               "| | | |",
               "\\ \\ / /",
               " \\ v / ",
               "  \\_/  "
               }
        },
        {'w', {" _ _ _ ",
               "||| |||",
               "||| |||",
               "||| |||",
               "|  ^  |",
               "\\_/ \\_/"
               }
        },
        {'x', {" _   _ ",
               "\\ \\ / /",
               " \\ v / ",
               "  > <  ",
               " / ^ \\ ",
               "/_/ \\_\\"
               }
        },
        {'y', {" _   _ ",
               "\\ \\ / /",
               " \\ v / ",
               "  > /  ",
               " / /   ",
               "/_/    "
               }
        },
        {'z', {" _____ ",
               "|___  |",
               "   / / ",
               "  / /  ",
               " / /__ ",
               "|_____|"
               }
        },
        {'1', {"     _ ",
               "    | |",
               "    | |",
               "    | |",
               "    | |",
               "    |_|"
               }
        },
        {'2', {" _____ ",
               "|___  |",
               " ___| |",
               "|  ___|",
               "| |___ ",
               "|_____|"
               }
        },
        {'3', {" _____ ",
               "|____ |",
               "   _| |",
               "  |_  |",
               " ___| |",
               "|_____|"
               }
        },
        {'4', {" _     ",
               "| |  _ ",
               "| |_| |",
               "|___  |",
               "    | |",
               "    |_|"
               }
        },
        {'5', {" _____ ",
               "|  ___|",
               "| |___ ",
               "|___  |",
               " ___| |",
               "|_____|"
               }
        },
        {'6', {" _____ ",
               "|  ___|",
               "| |___ ",
               "|  _  |",
               "| |_| |",
               "|_____|"
               }
        },
        {'7', {" _____ ",
               "|___  |",
               "    / /",
               "   / / ",
               "  / /  ",
               " /_/   "
               }
        },
        {'8', {" _____ ",
               "|  _  |",
               "| |_| |",
               "|  _  |",
               "| |_| |",
               "|_____|"
               }
        },
        {'9', {" _____ ",
               "|  _  |",
               "| |_| |",
               "|___  |",
               " ___| |",
               "|_____|"
               }
        },
        {'0', {" _____ ",
               "|  _  |",
               "| | | |",
               "| |\\| |",
               "| |_| |",
               "|_____|"
               }
        },
        {'.', {"       ",
               "       ",
               "       ",
               "       ",
               "   _   ",
               "  |_|  "
               }
        },
        {',', {"       ",
               "       ",
               "       ",
               "   _   ",
               "  | |  ",
               "  |_/  "
               }
        },
        {'!', {"   _   ",
               "  | |  ",
               "  | |  ",
               "  |_|  ",
               "   _   ",
               "  |_|  "
               }
        },
        {'?', {" ____ ",
               "/_/\\ \\ ",
               "   | | ",
               "  /_/  ",
               "   _   ",
               "  |_|  "
               }
        },
        {';', {"       ",
               "   _   ",
               "  |_|  ",
               "   _   ",
               "  | |  ",
               "  |_/  "
               }
        },
        {':', {"       ",
               "   _   ",
               "  |_|  ",
               "   _   ",
               "  |_|  ",
               "       "
               }
        },
        {' ', {"       ",
               "       ",
               "       ",
               "       ",
               "       ",
               "       "
               }
        },
        {'-', {"       ",
               "       ",
               " _____ ",
               "|_____|",
               "       ",
               "       "
               }
        },
        {'+', {"       ",
               "   _   ",
               " _| |_ ",
               "|_   _|",
               "  |_|  ",
               "       "
               }
        },
        {'_', {"       ",
               "       ",
               "       ",
               "       ",
               " _____ ",
               "|_____|"
               }
        }
    };

    return chars;
}

}

QString Backend::generateAsciiArt(QString &input)
{
    QString lines[6];

    for(auto c: input) {
        AsciiChar asc = artCharacters().value(c.toLower(), {});
        if(asc.d->isEmpty()) {
            qWarning() << "unknown character" << c << ". skipping...";
            continue;
        }
        for(int i = 0; i < 6; ++i)
            lines[i] += asc.d[i];
    }

    QString ret;
    for(int i = 0; i < 6; ++i) {
        ret += lines[i];
        if(i != 5) {
            ret += "\n";
        }
    }

    return ret;
}

} // namespace AsciiArt
