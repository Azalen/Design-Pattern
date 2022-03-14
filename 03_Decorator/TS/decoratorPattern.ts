// KOMPONENTE
interface IButton {
    operation(): string;
}

// KONKRETE KOMPONENTE
class Button implements IButton {
    public operation(): string {
        return 'Button-Komponente';
    }
}

// DEKORIERER
class Decorator implements IButton {
    protected component: IButton;

    constructor(component: IButton) {
        this.component = component;
    }

    /**
     * The Decorator delegates all work to the wrapped component.
     */
    public operation(): string {
        return this.component.operation();
    }
}

// KONKRETER DEKORIERER A
class ButtonPrimary extends Decorator {

    public operation(): string {
        return `ButtonPrimary(${super.operation()})`;
    }
}

// KONKRETER DEKORIERER B
class ButtonLarge extends Decorator {
    public operation(): string {
        return `ButtonLarge(${super.operation()})`;
    }
}


function clientCode(component: IButton) {
    console.log(`RESULT: ${component.operation()}`);
}

const button = new Button();
clientCode(button);

const dekorierterButton = new ButtonLarge(new ButtonPrimary(new Button()));
clientCode(dekorierterButton);