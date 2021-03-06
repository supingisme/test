// Written by David Hallas to trigger this bug in Valgrind:
// https://bugs.kde.org/show_bug.cgi?id=359133

#define CONCAT2(x, y) x##y
#define CONCAT(x, y) CONCAT2(x, y)

#define AllLetters ABCDEFGHIJKLMNOPQRSTUVXYZabcdefghijklmnopqrstuvxyzABCDEFGHIJKLMNOPQRSTUVXYZabcdefghijklmnopqrstuvxyzABCDEFGHIJKLMNOPQRSTUVXYZabcdefghijklmnopqrstuvxyzABCDEFGHIJKLMNOPQRSTUVXYZABCDEFGHIJKLMNOPQRSTUVXYZabcdefghijklmnopqrstuvxyzABCDEFGHIJKLMNOPQRSTUVXYZabcdefghijklmnopqrstuvxyzABCDEFGHIJKLMNOPQRSTUVXYZabcdefghijklmnopqrstuvxyzABCDEFGHIJKLMNOPQRSTUVXYZABCDEFGHIJKLMNOPQRSTUVXYZabcdefghijklmnopqrstuvxyzABCDEFGHIJKLMNOPQRSTUVXYZabcdefghijklmnopqrstuvxyzABCDEFGHIJKLMNOPQRSTUVXYZabcdefghijklmnopqrstuvxyzABCDEFGHIJKLMNOPQRSTUVXYZABCDEFGHIJKLMNOPQRSTUVXYZabcdefghijklmnopqrstuvxyzABCDEFGHIJKLMNOPQRSTUVXYZabcdefghijklmnopqrstuvxyzABCDEFGHIJKLMNOPQRSTUVXYZabcdefghijklmnopqrstuvxyzABCDEFGHIJKLMNOPQRSTUVXYZABCDEFGHIJKLMNOPQRSTUVXYZabcdefghijklmnopqrstuvxyzABCDEFGHIJKLMNOPQRSTUVXYZabcdefghijklmnopqrstuvxyzABCDEFGHIJKLMNOPQRSTUVXYZabcdefghijklmnopqrstuvxyzABCDEFGHIJKLMNOPQRSTUVXYZABCDEFGHIJKLMNOPQRSTUVXYZabcdefghijklmnopqrstuvxyzABCDEFGHIJKLMNOPQRSTUVXYZabcdefghijklmnopqrstuvxyzABCDEFGHIJKLMNOPQRSTUVXYZabcdefghijklmnopqrstuvxyzABCDEFGHIJKLMNOPQRSTUVXYZABCDEFGHIJKLMNOPQRSTUVXYZabcdefghijklmnopqrstuvxyzABCDEFGHIJKLMNOPQRSTUVXYZabcdefghijklmnopqrstuvxyzABCDEFGHIJKLMNOPQRSTUVXYZabcdefghijklmnopqrstuvxyzABCDEFGHIJKLMNOPQRSTUVXYZABCDEFGHIJKLMNOPQRSTUVXYZabcdefghijklmnopqrstuvxyzABCDEFGHIJKLMNOPQRSTUVXYZabcdefghijklmnopqrstuvxyzABCDEFGHIJKLMNOPQRSTUVXYZabcdefghijklmnopqrstuvxyzABCDEFGHIJKLMNOPQRSTUVXYZ
#define TemplateName(name) CONCAT(AllLetters, name)
#define TemplateDef(name) class TemplateName(name) {};

TemplateDef(1)
TemplateDef(2)
TemplateDef(3)
TemplateDef(4)
TemplateDef(5)
TemplateDef(6)
TemplateDef(7)
TemplateDef(8)
TemplateDef(9)
TemplateDef(10)
TemplateDef(11)
TemplateDef(12)
TemplateDef(13)
TemplateDef(14)
TemplateDef(15)
TemplateDef(16)
TemplateDef(17)
TemplateDef(18)
TemplateDef(19)
TemplateDef(20)
TemplateDef(21)
TemplateDef(22)
TemplateDef(23)
TemplateDef(24)
TemplateDef(25)
TemplateDef(26)
TemplateDef(27)
TemplateDef(28)
TemplateDef(29)
TemplateDef(30)
TemplateDef(31)
TemplateDef(32)
TemplateDef(33)
TemplateDef(34)
TemplateDef(35)
TemplateDef(36)
TemplateDef(37)
TemplateDef(38)
TemplateDef(39)
TemplateDef(40)
TemplateDef(41)
TemplateDef(42)
TemplateDef(43)
TemplateDef(44)
TemplateDef(45)
TemplateDef(46)
TemplateDef(47)
TemplateDef(48)
TemplateDef(49)
TemplateDef(50)

class MyTemplate {
public:
	template<typename... T>
	void foo();
};

template<>
void MyTemplate::foo<
		TemplateName(1),
		TemplateName(2),
		TemplateName(3),
		TemplateName(4),
		TemplateName(5),
		TemplateName(6),
		TemplateName(7),
		TemplateName(8),
		TemplateName(9),
		TemplateName(10),
		TemplateName(11),
		TemplateName(12),
		TemplateName(13),
		TemplateName(14),
		TemplateName(15),
		TemplateName(16),
		TemplateName(17),
		TemplateName(18),
		TemplateName(19),
		TemplateName(20),
		TemplateName(21),
		TemplateName(22),
		TemplateName(23),
		TemplateName(24),
		TemplateName(25),
		TemplateName(26),
		TemplateName(27),
		TemplateName(28),
		TemplateName(29),
		TemplateName(30),
		TemplateName(31),
		TemplateName(32),
		TemplateName(33),
		TemplateName(34),
		TemplateName(35),
		TemplateName(36),
		TemplateName(37),
		TemplateName(38),
		TemplateName(39),
		TemplateName(40),
		TemplateName(41),
		TemplateName(42),
		TemplateName(43),
		TemplateName(44),
		TemplateName(45),
		TemplateName(46),
		TemplateName(47),
		TemplateName(48),
		TemplateName(49),
		TemplateName(50)
>();

template<>
void MyTemplate::foo<
		TemplateName(1),
		TemplateName(2),
		TemplateName(3),
		TemplateName(4),
		TemplateName(5),
		TemplateName(6),
		TemplateName(7),
		TemplateName(8),
		TemplateName(9),
		TemplateName(10),
		TemplateName(11),
		TemplateName(12),
		TemplateName(13),
		TemplateName(14),
		TemplateName(15),
		TemplateName(16),
		TemplateName(17),
		TemplateName(18),
		TemplateName(19),
		TemplateName(20),
		TemplateName(21),
		TemplateName(22),
		TemplateName(23),
		TemplateName(24),
		TemplateName(25),
		TemplateName(26),
		TemplateName(27),
		TemplateName(28),
		TemplateName(29),
		TemplateName(30),
		TemplateName(31),
		TemplateName(32),
		TemplateName(33),
		TemplateName(34),
		TemplateName(35),
		TemplateName(36),
		TemplateName(37),
		TemplateName(38),
		TemplateName(39),
		TemplateName(40),
		TemplateName(41),
		TemplateName(42),
		TemplateName(43),
		TemplateName(44),
		TemplateName(45),
		TemplateName(46),
		TemplateName(47),
		TemplateName(48),
		TemplateName(49),
		TemplateName(50)
>()
{
}

int main(int argc, char* argv[])
{
	MyTemplate instance;
	instance.foo<
		TemplateName(1),
		TemplateName(2),
		TemplateName(3),
		TemplateName(4),
		TemplateName(5),
		TemplateName(6),
		TemplateName(7),
		TemplateName(8),
		TemplateName(9),
		TemplateName(10),
		TemplateName(11),
		TemplateName(12),
		TemplateName(13),
		TemplateName(14),
		TemplateName(15),
		TemplateName(16),
		TemplateName(17),
		TemplateName(18),
		TemplateName(19),
		TemplateName(20),
		TemplateName(21),
		TemplateName(22),
		TemplateName(23),
		TemplateName(24),
		TemplateName(25),
		TemplateName(26),
		TemplateName(27),
		TemplateName(28),
		TemplateName(29),
		TemplateName(30),
		TemplateName(31),
		TemplateName(32),
		TemplateName(33),
		TemplateName(34),
		TemplateName(35),
		TemplateName(36),
		TemplateName(37),
		TemplateName(38),
		TemplateName(39),
		TemplateName(40),
		TemplateName(41),
		TemplateName(42),
		TemplateName(43),
		TemplateName(44),
		TemplateName(45),
		TemplateName(46),
		TemplateName(47),
		TemplateName(48),
		TemplateName(49),
		TemplateName(50)
	>();
	return 0;
}

