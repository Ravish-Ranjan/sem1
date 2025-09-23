## React
>
    // React component with state
    function TodoList() {
        const [todos, setTodos] = useState([]);
        const [inputValue, setInputValue] = useState('');
        
        const addTodo = () => {
            setTodos([...todos, { id: Date.now(), text: inputValue, done: false }]);
            setInputValue('');
        };
        
        return (
            <div>
                <input 
                    value={inputValue}
                    onChange={(e) => setInputValue(e.target.value)}
                />
                <button onClick={addTodo}>Add Todo</button>
                <ul>
                    {todos.map(todo => (
                        <li key={todo.id} className={todo.done ? 'done' : ''}>
                            {todo.text}
                        </li>
                    ))}
                </ul>
            </div>
        );
    }

### react direct access
>
    function FocusInput() {
        const inputRef = useRef(null);
        
        const focusInput = () => {
            inputRef.current.focus();
        };
        
        return (
            <div>
                <input ref={inputRef} type="text" />
                <button onClick={focusInput}>Focus Input</button>
            </div>
        );
    }

### vue js
>
    <template>
        <div class="todo-app">
            <input v-model="newTodo" @keyup.enter="addTodo">
            <button @click="addTodo">Add</button>
            
            <ul>
                <li v-for="todo in todos" 
                    :key="todo.id" 
                    :class="{ done: todo.completed }"
                    @click="toggleTodo(todo)">
                    {{ todo.text }}
                </li>
            </ul>
            
            <p v-if="todos.length === 0">No todos yet!</p>
        </div>
    </template>
    
    <script>
    export default {
        data() {
            return {
                newTodo: '',
                todos: []
            };
        },
        methods: {
            addTodo() {
                if (this.newTodo.trim()) {
                    this.todos.push({
                        id: Date.now(),
                        text: this.newTodo,
                        completed: false
                    });
                    this.newTodo = '';
                }
            },
            toggleTodo(todo) {
                todo.completed = !todo.completed;
            }
        }
    };
    </script>

### vue directives for dom manipulation
>
    <template>
        <!-- Conditional rendering -->
        <div v-if="showModal" class="modal">Modal content</div>
        
        <!-- List rendering -->
        <div v-for="item in items" :key="item.id">{{ item.name }}</div>
        
        <!-- Dynamic attributes -->
        <button :disabled="isLoading" :class="buttonClass">Submit</button>
        
        <!-- Event handling -->
        <button @click="handleClick" @mouseover="handleHover">Click me</button>
    </template>

### angular
>
    // Component TypeScript
    @Component({
        selector: 'app-todo',
        template: `
            <div class="todo-container">
                <input [(ngModel)]="newTodoText" 
                    (keyup.enter)="addTodo()"
                    placeholder="Add new todo">
                <button (click)="addTodo()" [disabled]="!newTodoText">Add</button>
                
                <ul *ngIf="todos.length > 0">
                    <li *ngFor="let todo of todos; trackBy: trackByFn"
                        [class.completed]="todo.completed"
                        (click)="toggleTodo(todo)">
                        {{ todo.text }}
                    </li>
                </ul>
                
                <div *ngIf="todos.length === 0" class="empty-state">
                    No todos yet!
                </div>
            </div>
        `
    })
    export class TodoComponent {
        newTodoText = '';
        todos: Todo[] = [];
        
        addTodo() {
            if (this.newTodoText.trim()) {
                this.todos.push({
                    id: Date.now(),
                    text: this.newTodoText,
                    completed: false
                });
                this.newTodoText = '';
            }
        }
        
        toggleTodo(todo: Todo) {
            todo.completed = !todo.completed;
        }
        
        trackByFn(index: number, item: Todo) {
            return item.id;
        }
    }

### angular direct dom access
>
    @Component({...})
    export class MyComponent implements AfterViewInit {
        @ViewChild('myInput') inputRef!: ElementRef;
        
        constructor(private renderer: Renderer2) {}
        
        ngAfterViewInit() {
            // Direct DOM access
            this.inputRef.nativeElement.focus();
            
            // Using Renderer2 (recommended)
            this.renderer.setStyle(this.inputRef.nativeElement, 'border', '2px solid blue');
        }
    }