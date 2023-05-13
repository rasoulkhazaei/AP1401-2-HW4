const list = document.getElementById('list');
const loading = document.getElementById('loading');
const spinner = document.getElementById('loading-spinner');

loading.style.display = 'block';

// This is the content that will show in first place
function main_content() {
    fetch('https://swapi.dev/api/films/')
        .then(response => response.json())
        .then(data => {
            const items = data.results.map(item => `<li> <strong>Title:</strong> ${item.title}
            - <strong>Episode:</strong> ${item.episode_id} - <strong>Release date:</strong> ${item.release_date}</li>
            <button class="button starships" id="${item.episode_id}">Starships</button>`);


            list.innerHTML = items.join('');
            loading.style.display = 'none';

            // Add the event listener to the button
            const starshipButtons = document.querySelectorAll('.starships');
            starshipButtons.forEach(button => {
                button.addEventListener('click', event => {
                    const episodeId = event.target.id;
                    showStarships(episodeId);
                });
            });
        }).catch(error => {
            console.log('Error fetching data:', error);
            loading.style.display = 'none';
        });
}

// This is content that will show in starship page
async function showStarships(episodeId) {
    let body = document.getElementById("body");
    body.innerHTML = '<div class="content" id="content"> <h1>List of Starships</h1> <button class="button back-button" id="back-button">Back</button> <ul id="list"></ul> </div>';

    const response = await fetch(`https://swapi.dev/api/films/${episodeId}/`);
    const data = await response.json();
    const items = [];

    for (let url of data.starships) {
        const starshipResponse = await fetch(url);
        const starshipData = await starshipResponse.json();
        items.push(`<li>${starshipData.name} <button class="button starship-details" data-url="${url}">Details</button></li>`);
    }

    const list = document.getElementById('list');
    list.innerHTML = items.join('');

    // Add the event listener to the button
    const starshipDetailsButtons = document.querySelectorAll('.starship-details');
    starshipDetailsButtons.forEach(button => {
        button.addEventListener('click', event => {
            const url = event.target.dataset.url;
            showStarshipDetails(url);
        });
    });

    // Add the event listener to the back button
    const backButton = document.querySelector("back-button");
    backButton.addEventListener('click', event => {
        main_content();
    });
}

// This is content that will show starship details
async function showStarshipDetails(url) {
    let body = document.getElementById("body");
    body.innerHTML = '<div class="content" id="content"> <h1>Starship Details</h1> <button class="button back-button">Back</button> <div id="details"></div> </div>';

    const response = await fetch(url);
    const data = await response.json();

    const details = document.getElementById('details');
    const html = `<p><strong>Name:</strong> ${data.name}</p>
                  <p><strong>Model:</strong> ${data.model}</p>
                  <p><strong>Manufacturer:</strong> ${data.manufacturer}</p>
                  <p><strong>Cost in credits:</strong> ${data.cost_in_credits}</p>
                  <p><strong>Length:</strong> ${data.length}</p>
                  <p><strong>Max atmosphering speed:</strong> ${data.max_atmosphering_speed}</p>
                  <p><strong>Crew:</strong> ${data.crew}</p>
                  <p><strong>Passengers:</strong> ${data.passengers}</p>
                  <p><strong>Cargo capacity:</strong> ${data.cargo_capacity}</p>
                  <p><strong>Hyperdrive rating:</strong> ${data.hyperdrive_rating}</p>
                  <p><strong>MGLT:</strong> ${data.MGLT}</p>
                  <p><strong>Starship class:</strong> ${data.starship_class}</p>`;
    details.innerHTML = html;

    const backButton = document.querySelector('.back-button');
    backButton.addEventListener('click', event => {
        main_content();
    });
}

window.addEventListener('load', main_content);
