document.addEventListener("DOMContentLoaded", function() {
    const bodyTop = document.querySelector('.body_top');
    const images = bodyTop.querySelectorAll('img');
    let counter = 0;

    setInterval(() => {
        images[counter].style.opacity = 0;
        counter = (counter + 1) % images.length;
        images[counter].style.opacity = 1;
    }, 3000);
});
