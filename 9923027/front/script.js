function create_li(text, id) {
    let li = document.createElement('li');
    li.textContent = text;
    li.setAttribute('id', id);
    return li;
}

function create_ul(id) {
    let li = document.createElement('ul');
    li.setAttribute('id', id);
    return li;
}

function create_a(text, url) {
    let myAnchor = document.createElement('a');
    let textToLink = document.createTextNode(text);
    myAnchor.appendChild(textToLink);
    myAnchor.href = url;
    return myAnchor;
}
function create_button(text, id) {
    let myAnchor = document.createElement('button');
    let textToLink = document.createTextNode(text);
    myAnchor.appendChild(textToLink);
    myAnchor.setAttribute('id', id);
    return myAnchor;
}
function create_h1(text, id) {
    let myAnchor = document.createElement('h1');
    let textToLink = document.createTextNode(text);
    myAnchor.appendChild(textToLink);
    myAnchor.setAttribute('id', id);
    return myAnchor;
}

function create_div(id) {
    let myAnchor = document.createElement('div');
    myAnchor.setAttribute('id', id);
    return myAnchor;
}

async function getapi(url) {
    try {
        const response = await fetch(url);
        let data = await response.json();
        return data;
    } catch (err) {
        console.log(err);
    }
}

const Movies = [];

async function getapimovie(url) {
    try {
        const response = await fetch(url);
        let data = await response.json();
        // code here

        // create lists
        let list = document.getElementById("Movielist");
        list.appendChild(create_li(`${data['title']} , ${data['episode_id']} , ${data['release_date']} `, `li${data['episode_id']}`));
        Movies.push(`${data['title']} , ${data['episode_id']} , ${data['release_date']} `);
        // console.log(Movies);
        // create buttons
        let li = document.getElementById(`li${data['episode_id']}`);
        li.appendChild(create_button('Starships', `${data['episode_id']}`));

        let button = document.getElementById(`${data['episode_id']}`);

        button.addEventListener("click", () => {
            let movielist = document.getElementById('Movielist');
            movielist.remove();
            let main_box = document.getElementById('main_box');
            main_box.appendChild(create_div('box1'));
            main_box.appendChild(create_div('box2'));
            main_box.appendChild(create_button('Back', 'Back'))
            let Back = document.getElementById('Back');
            // Back Button
            Back.addEventListener("click", () => {
                let box1 = document.getElementById('box1');
                let box2 = document.getElementById('box2');
                let Back = document.getElementById('Back');
                Back.remove();
                box1.remove();
                box2.remove();
                let main_box = document.getElementById('main_box');
                main_box.appendChild(create_ul('Movielist'));
                let movielist = document.getElementById('Movielist');
                movielist.appendChild(create_h1('Movies', ''));

                getapimovie('https://swapi.dev/api/films/4')
                getapimovie('https://swapi.dev/api/films/5')
                getapimovie('https://swapi.dev/api/films/6')
                getapimovie('https://swapi.dev/api/films/1')
                getapimovie('https://swapi.dev/api/films/2')
                getapimovie('https://swapi.dev/api/films/3')

                // for (let i = 0; i < Movies.length; i++) {
                //     const films_data = Movies[i];
                //     let list = document.getElementById("Movielist");
                //     list.appendChild(create_li(films_data, `${data['episode_id']}`));
                //     let li = document.getElementById(`${data['episode_id']}`);
                //     button = li.appendChild(create_button('Starships', `${data['episode_id']}`));
                // }

            });
            // Back Button
            let box1 = document.getElementById('box1');
            box1.appendChild(create_h1('Starships'));
            box1.appendChild(create_ul('box1ulist'));
            for (let i = 0; i < data['starships'].length; i++) {
                const starshipapi = data['starships'][i];
                getapistarships(starshipapi, i);
            }
        });
        // button.addEventListener("click", getapistarships(`${data['starships']}`));
        // code here
    } catch (err) {
        console.log(err);
    }
}

// let Back = document.getElementById('Back');

async function getapistarships(url, i) {
    try {
        const response = await fetch(url);
        let data = await response.json();
        // code here
        let ul = document.getElementById('box1ulist');
        ul.appendChild(create_li('', 'list' + i));

        let li = document.getElementById('list' + i); // 'list' + i
        li.appendChild(create_button(`${data['name']}`, 'list' + i)); // 'list' + i

        let button = document.getElementById('list' + i);

        button.addEventListener("click", () => {

            let box2 = document.getElementById('box2');
            box2.remove();
            let main_box = document.getElementById('main_box');
            main_box.appendChild(create_div('box2'));
            box2 = document.getElementById('box2');
            box2.appendChild(create_h1(`${data['name']}`));
            box2.appendChild(create_ul('box2ulist'));
            let ulbox2 = document.getElementById('box2ulist');
            ulbox2.appendChild(create_li(`${data['model']}`, ''));
            ulbox2.appendChild(create_li(`${data['manufacturer']}`, ''));
            ulbox2.appendChild(create_li(`${data['crew']}`, ''));
            ulbox2.appendChild(create_li(`${data['passengers']}`, ''));
            for (let i = 0; i < data['films'].length; i++) {
                const starshipapi = data['films'][i];
                getapistarshipsfilm(starshipapi, i);
            }
        });
        // code here
    } catch (err) {
        console.log(err);
    }
}

async function getapistarshipsfilm(url, i) {
    try {
        const response = await fetch(url);
        let data = await response.json();
        // code here

        let ulbox2 = document.getElementById('box2ulist');
        ulbox2.appendChild(create_li(`${data['title']}`, ''));
        // code here
    } catch (err) {
        console.log(err);
    }
}
getapimovie('https://swapi.dev/api/films/4')
getapimovie('https://swapi.dev/api/films/5')
getapimovie('https://swapi.dev/api/films/6')
getapimovie('https://swapi.dev/api/films/1')
getapimovie('https://swapi.dev/api/films/2')
getapimovie('https://swapi.dev/api/films/3')
