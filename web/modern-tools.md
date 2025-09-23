## Modern Tools
### web componenets
>
    class CustomButton extends HTMLElement {
        constructor() {
            super();
            this.attachShadow({ mode: 'open' });
            this.render();
        }
        
        static get observedAttributes() {
            return ['label', 'variant'];
        }
        
        attributeChangedCallback(name, oldValue, newValue) {
            if (oldValue !== newValue) {
                this.render();
            }
        }
        
        render() {
            const label = this.getAttribute('label') || 'Click me';
            const variant = this.getAttribute('variant') || 'primary';
            
            this.shadowRoot.innerHTML = `
                <style>
                    button {
                        padding: 10px 20px;
                        border: none;
                        border-radius: 4px;
                        cursor: pointer;
                        font-family: inherit;
                    }
                    .primary { background: #007bff; color: white; }
                    .secondary { background: #6c757d; color: white; }
                </style>
                <button class="${variant}" onclick="this.dispatchEvent(new CustomEvent('custom-click', { bubbles: true }))">
                    ${label}
                </button>
            `;
        }
    }
    
    customElements.define('custom-button', CustomButton);

### usage
>
    <custom-button label="Save" variant="primary"></custom-button>
    <custom-button label="Cancel" variant="secondary"></custom-button>
    
    <script>
    document.addEventListener('custom-click', (event) => {
        console.log('Custom button clicked!');
    });
    </script>



| Tool                                 | Role                             | Key Advantage                            |
| ------------------------------------ | -------------------------------- | ---------------------------------------- |
| **Web Components (Custom Elements)** | Define reusable custom tags      | Standardized encapsulated components     |
| **Shadow DOM**                       | Encapsulation of markup & styles | No CSS leakage or conflicts              |
| **Intersection Observer API**        | Observe visibility in viewport   | Efficient lazy-loading & animations      |
| **Mutation Observer API**            | Observe DOM changes              | React to dynamic content without polling |
| **Modern CSS (Grid, Flexbox)**       | Layout system                    | Reduces need for JS-based positioning    |
| **Virtual DOM (React, Vue)**         | Efficient DOM updates            | Abstracts away direct DOM manipulation   |
