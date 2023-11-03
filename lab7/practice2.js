function changeStyles() {
    const colorInput = document.getElementById("colorInput").value;
    const borderWidth = document.getElementById("borderWidth").value;

    const rgbValues = colorInput.split(",").map(value => parseInt(value.trim()));
    const color = `rgb(${rgbValues[0]}, ${rgbValues[1]}, ${rgbValues[2]})`;

    const paragraph = document.getElementById("colorPara");
    paragraph.style.color = color;
    paragraph.style.border = `${borderWidth}px solid ${color}`;

    const borderWidthValue = document.getElementById("borderWidthValue");
    borderWidthValue.textContent = borderWidth;
}