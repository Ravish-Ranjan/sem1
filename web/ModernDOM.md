# Modern framework's DOM/DOM manipulation

## Angular
### 1. Angular’s Approach
>
    
    Angular compiles your templates (.html) into efficient JavaScript instructions.
    
    These instructions tell Angular how to create and update the DOM nodes directly (no virtual copy).
    
    When data changes, Angular runs change detection and updates the necessary DOM parts in place.

### 2. Change Detection
>
    
    Angular uses zone.js (by default) to know when something asynchronous happens (HTTP call, click, setTimeout, promise, etc.).
    
    After that async task, Angular runs a change detection cycle:
    
    It traverses the component tree.
    
    For each component, it checks if the bound data changed.
    
    If changed → Angular updates the real DOM node directly.

## React
### 1. Render → Create VDOM tree
>

Your component (render() in React, for example) produces a Virtual DOM tree.

This is a lightweight JS object representation of your UI.
>
    {
    type: "div",
    props: { className: "card" },
    children: [
        { type: "h1", props: {}, children: ["Hello"] },
        { type: "p", props: {}, children: ["World"] }
    ]
    }


### 2. Initial Mount → Build Real DOM

On first render, React (or another VDOM library) takes that VDOM tree and builds the real DOM nodes.

Inserts them into the page.

### 3. State/Props Change → New VDOM Tree

When your data changes, a new VDOM tree is created (not a mutation, but a fresh object structure).

`Diffing (Reconciliation)`

The library compares the new VDOM with the previous VDOM.

This is usually done using heuristics (same type → reuse, different type → replace).

Example:
>
    Old VDOM: <p>Hello</p>
    
    New VDOM: <p>Hi</p>

`Diff algorithm: same element type, just update textContent.`

Patch Real DOM (Minimal Updates)

After diffing, it produces a list of minimal real DOM changes.

Updates only what changed (e.g., just change the text, instead of re-rendering the whole `<p>`).

`The Virtual DOM (VDOM) is called lightweight not because it has fewer "conceptual nodes", but because its nodes are just plain JavaScript objects, not full browser Node objects.`