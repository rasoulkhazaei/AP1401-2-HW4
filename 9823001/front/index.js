const main = document.getElementById("main");
const API_FILMS = "https://swapi.dev/api/films/"; // api address
const dataSheeps = []; // use for save sheeps data


// call api for get movies page content
const getMoviesPageContent = async () => {
    const response = await fetch(API_FILMS);
    const dataFetched = await response.json();
    dataSheeps.push(...dataFetched.results);
};

// initial rendering => moviesPage
const initialRendering = async () => {
    await getMoviesPageContent();
    MoviesPage();
};

// change whole main content
// => use for change page
const setMainHTML = (jsx) => {
    main.innerHTML = jsx;
};


// for show data of each sheep
const showDataFromSheepData = (data) => {
    const jsxArray = ['<h2 class="h2-detail">Starsheep Detail</h2>'];

    // data is obj so for use like array we need to use Object.keys
    Object.keys(data).forEach((dataObj) => {
        const jsx = `<li class="detail__item">${dataObj}: <span class="detail__item-data">${data[dataObj].length > 0 ? data[dataObj] : "_"
            }</span></li>`;
        jsxArray.push(jsx);
    });

    // get sheep detail element from html
    const sheepDetail = document.getElementById("sheep-detail");
    sheepDetail.innerHTML = jsxArray.join(""); // set html content of sheep detail element
};

// show sheep name for each film via api
const getSheepInformationHandler = async (starshipsUrlArray) => {
    const jsx = `<div class="starsheeps"><h1>Starsheep Films</h1><div class="sheep-content"><ul class="sheep__names" id="sheep-name"><h2>Sheep Names</h2></ul><ul class="sheep__detail" id="sheep-detail"></ul></div><button class="back__tomovies" id="back-tomovies">Back To Movies</button></div>`;
    setMainHTML(jsx);

    const backToMoviesElement = document.getElementById("back-tomovies"); // button for goes on MoviesPage

    backToMoviesElement.addEventListener('click', MoviesPage);

    const sheepNameContainerElement = document.getElementById("sheep-name");

    for (let i = 0; i < starshipsUrlArray.length; i++) {
        const api = starshipsUrlArray[i];
        const response = await fetch(api);
        const sheepData = await response.json();

        const sheepNameElement = document.createElement("li"); // create sheep Name element
        sheepNameElement.classList.add("sheep__name");
        sheepNameElement.innerText = sheepData.name;

        sheepNameElement.addEventListener("click", () =>
            showDataFromSheepData(sheepData)
        );

        // append name element into list
        sheepNameContainerElement.appendChild(sheepNameElement);
    }
};

const MoviesPage = () => {
    let jsx =
        '<h1>Movies</h1><div class="titles"><div class="titles__info"><span class="titles__item">TITLE</span><span class="titles__item">EN</span><span class="titles__item">CREATED TIME</span></div><span class="titles__item">StarSheeps</span></div><ul class="movies__list" id="movies-list"></ul>'; // javascript xml codes

    setMainHTML(jsx);

    if (dataSheeps.length > 0) {
        dataSheeps.forEach((dataObj, index) => {
            //  get film detail from data Sheep array
            const title = dataObj.title;
            const episodeNumber = dataObj.episode_id;
            const releaseDate = dataObj.release_date;
            const sheepData = dataObj.starships;

            const movieItem = document.createElement("li"); // create movie item
            movieItem.classList.add("movie");

            movieItem.innerHTML = `<div class="movie__info"><span class="movie__title">${title}</span><span class="movie__episod-number">${episodeNumber}</span><span class="movie__created-date">${releaseDate}</span></div><a href="#" class="movie__link" id="movie-${index}" > Starshipes</a>`; // add jsx code for movie item

            const moviesList = document.getElementById("movies-list");

            moviesList.appendChild(movieItem); // add movie item into movie list

            const movieLink = document.getElementById(`movie-${index}`);
            movieLink.addEventListener("click", () =>
                getSheepInformationHandler(sheepData)
            );
        });
    }
};

// call initial rendering
initialRendering();
