# 3-ий семестр ООП: Конспекты от Банковского Александра Сергеевича #

## include guard  ##

include guard - это особая конструкция, применяемая для избегания 
проблем с «двойным подключением». Он позволяет при множественном 
подключении одного и того же файла сделать его подключения 
эквивалентным однократному вызову.

### Пример без использования guard:###

**Файл grandfather.h:**

    struct foo { // Объявление структуры "foo"
        int member; 
    };

**Файл father.h:**

    // Подключение файла,
    // в котором объявлена структура 
    #include "grandfather.h" 

**Файл child.c:**

    #include "grandfather.h"
    #include "father.h" // Здесь структура foo объявляется 2-ой раз
    // Это может вызвать ошибку компиляции

### Применение guards:###

**Файл grandfather.h:**

    #ifndef H_GRANDFATHER // Проверка на повторное подключение
    #define H_GRANDFATHER // Если уже подключено, то пропускаем всё,
    // что идёт до #endif
    struct foo {
        int member;
    };
 
     #endif

**Файл father.h:**

    // Подключение файла,
    // в котором объявлена структура 
    #include "grandfather.h" 

**Файл child.c:**
    
    #include "grandfather.h"
    #include "father.h" // Здесь структура foo объявляется 2-ой раз
    // С помощью guard ошибки уже не возникнет, ибо будет пропуск повторного объявления
    
Я считаю, что пример немного утрирован, ибо ошибку можно легко избежать, к сожалению Я не хочу придумывать собственный пример...
Информация взята с [википедии](https://ru.wikipedia.org/wiki/Include_guard)





## Перечисляемые типы данных ##

Это тип данных, чьё множество значений представляет ограниченный список идентификаторов.
Используется для упрощения работы и для лучшего понимания кода

### Синтаксис ###
    enum *Наименование* {
        ... 
        ...     // Список идентификаторов через запятую, кроме последнего
        ...     // Последний элемент множества пишется без любых знаков
    }
### Пример ###
    enum Enemy_State { // Объявление перечисляемого типа данных
        SLEEP,      // А именно здесь перечисляемый тип данных
        WALK,       // Это состояния врага/противника
        ALARMED,
        HUNTING_TO_PLAYER,
        AFRAID,
        DEAD
    };

    struct Enemy {                                // Обяъвление структуры "Враг"

    public:

        Enemy_State Get_State() { return State; } // Получение состояния врага

        void Set_State(Enemy_State State) {       // Установка состояния врагу
            this->State = State;
        }

        

    private:
        Enemy_State State;                        // Значение состояния врага
        float speed, damage;

    };


    void Get_State_Enemy(Enemy en) { // Функция для вывода состояния врага
        switch (en.Get_State())
        {
        case Enemy_State::SLEEP:
            cout << "спит...";
            break;
        case Enemy_State::WALK:
            cout << "просто ходит...";
            break;
        case Enemy_State::ALARMED:
            cout << "встревожен..";
            break;
        case Enemy_State::HUNTING_TO_PLAYER:
            cout << "бежит за мной!";
            break;
        case Enemy_State::AFRAID:
            cout << "напуган..";
            break;
        case Enemy_State::DEAD:
            cout << "мёртв..";
            break;
        }
    }

    int main()
    {
        setlocale(LC_ALL, "Russian");

        Enemy Goblin; // Объявляем новый объект класса Enemy - гоблина

        Goblin.Set_State(Enemy_State::SLEEP);                           // Меняет значения состояния гоблина 
        cout << "Вы замечаете врага...\nКажется он "; 
        Get_State_Enemy(Goblin);                                        // и выводим их на экран
        cout << "*Хруст ветки под ногой*\nОй-ой...";
        Goblin.Set_State(Enemy_State::ALARMED);
        cout << "\nтеперь он ";
        Get_State_Enemy(Goblin);
        cout << "\nОн оглядыватся.. Нет! Он меня заметил!\nТеперь он "; // В виде истории небольшой...
        Goblin.Set_State(Enemy_State::HUNTING_TO_PLAYER);
        Get_State_Enemy(Goblin);
        cout << "\n*Длительное преследование, заканчившееся хорошо для Вас...*\n";
        Goblin.Set_State(Enemy_State::ALARMED);
        cout << "Он потерял Вас из виду... теперь он ";
        Get_State_Enemy(Goblin);
        cout << "\n*Громкий неразборчивый рёв со стороны леса*\n";
        Goblin.Set_State(Enemy_State::AFRAID);
        cout << "Что это было?.. *Гоблин замер*\nКажется он ";
        Get_State_Enemy(Goblin);
        cout << "\n\n\tКонец!\n\n";

        system("pause");
        return 0;
    }
    
    
Информация взята с [YouTube](https://www.youtube.com/watch?v=BMmbQ81lQd0&t=538s)


