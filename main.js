fetch("./menu.html")
  .then(response => {
    return response.text()
  })
  .then(data => {
    document.querySelector("menu").innerHTML = data;
  });

fetch("./content1.html")
  .then(response => {
    return response.text()
  })
  .then(data => {
    document.querySelector("content1").innerHTML = data;
  });

fetch("./seccionmateriales.html")
  .then(response => {
    return response.text()
  })
  .then(data => {
    document.querySelector("seccionmateriales").innerHTML = data;
  });

fetch("./montaje.html")
  .then(response => {
    return response.text()
  })
  .then(data => {
    document.querySelector("montaje").innerHTML = data;
  });

fetch("./codigo.html")
  .then(response => {
    return response.text()
  })
  .then(data => {
    document.querySelector("codigo").innerHTML = data;
  });

fetch("./web.html")
  .then(response => {
    return response.text()
  })
  .then(data => {
    document.querySelector("web").innerHTML = data;
  });

fetch("./seccionvideo.html")
  .then(response => {
    return response.text()
  })
  .then(data => {
    document.querySelector("seccionvideo").innerHTML = data;
  });

fetch("./footer.html")
  .then(response => {
    return response.text()
  })
  .then(data => {
    document.querySelector("footer").innerHTML = data;
  });
