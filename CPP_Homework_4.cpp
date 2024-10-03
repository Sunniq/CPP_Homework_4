#include <iostream>
#include <memory>
#include <string>

class Weapon {
public:
    virtual ~Weapon() = default;
    virtual float GetDamage() const = 0;
    virtual std::string GetName() const = 0;
};

class Sword : public Weapon {
public:
    float GetDamage() const override {
        return 50.0f;
    }
    std::string GetName() const override {
        return "Sword";
    }
};

class Axe : public Weapon {
public:
    float GetDamage() const override {
        return 70.0f;
    }
    std::string GetName() const override {
        return "Axe";
    }
};

class Bow : public Weapon {
public:
    float GetDamage() const override {
        return 30.0f;
    }
    std::string GetName() const override {
        return "Bow";
    }
};

class Character {
public:
    void SetWeapon(std::unique_ptr<Weapon> new_weapon) {
        weapon = std::move(new_weapon);
    }

    Weapon* GetWeapon() const {
        return weapon.get();
    }

private:
    std::unique_ptr<Weapon> weapon;
};

int main() {
    Character character;


    int input;
    std::cout << "Enter a value from 1 to 3\n";
    while (std::cin >> input) {
        switch (input) {
        case 1:
            character.SetWeapon(std::make_unique<Sword>());
            std::cout << "Character has a " << character.GetWeapon()->GetName()
                << " with damage " << character.GetWeapon()->GetDamage() << std::endl;
            break;
        case 2:
            character.SetWeapon(std::make_unique<Axe>());
            std::cout << "Character has a " << character.GetWeapon()->GetName()
                << " with damage " << character.GetWeapon()->GetDamage() << std::endl;
            break;
        case 3:
            character.SetWeapon(std::make_unique<Bow>());
            std::cout << "Character has a " << character.GetWeapon()->GetName()
                << " with damage " << character.GetWeapon()->GetDamage() << std::endl;
            break;
        default:
            return 0;
        }
    }
    return 0;
}