'use strict';
const fs = require('fs');
const path = require('path');
const compRoot = path.resolve(__dirname, '..', 'addons', 'compositions');

function sanitize(str) {
    const ret = str.replace(/[^a-zA-Z0-9]+/g, '');
    return 'fpa_' + ret;
}

function readFolder(p) {
    return new Promise(resolve => {
        fs.readdir(p, 'utf8', (e, files) => {
            if (e) throw e;
            resolve(files.map(v => path.join(p, v)));
        });
    });
}

function mapFiles(folder) {
    return readFolder(folder)
        .then(files => {
            files = files.filter(f => f.endsWith('.hpp'))
                .sort((a, b) => path.basename(a).localeCompare(path.basename(b)));
            return {folder, files};
        });
}

function indent(times) {
    return ' '.repeat(times * 4);
}

function prepareText(allFolders) {
    let i = 3;
    let text = [];
    allFolders
        .filter(v => !!v.files.length)
        .sort((a, b) => path.basename(a.folder).locareCompare(path.basename(b.folder)))
        .forEach(obj => {
            const {folder, files} = obj;
            const folderBase = path.basename(folder);
            text.push(`${indent(i)}class ${sanitize(folderBase)}\r\n${indent(i++)}{`);
            text.push(`${indent(i)}name = "${folderBase}"`);
            files.forEach(file => {
                const fileBase = path.basename(file, '.hpp');
                text.push(`${indent(i)}class ${sanitize(fileBase)}\r\n${indent(i++)}{`);
                text.push(`${indent(i)}name = "${fileBase}";`);
                text.push(`${indent(i)}#include "src\\${folderBase}\\${fileBase}.hpp"\r\n${indent(--i)}};`);
            });
            text.push(`${indent((--i))}};`)
        })
    return text.join('\r\n');
}

function writeOutput(text) {
    const out = `
// Auto-generated file
#include "script_component.hpp"

class CfgGroups
{
    class Empty
    {
        side = 8;
        name = "Compositions";
        class GVAR(compositions)
        {
            name = "FPARMA";
${text}
        };
    };
};`;

    const file = path.join(compRoot, 'CfgGroups.hpp');
    fs.writeFileSync(file, out);
    console.log('Done, wrote ', file);
}

readFolder(path.join(compRoot, 'src')).then(directories => {
    Promise.all(
        directories
            .filter(v => fs.statSync(v).isDirectory())
            .map(mapFiles))
        .then(allFolders => {
            console.info(`Found ${allFolders.length} folders, ${allFolders.reduce((val, cur) => val + cur.files.length, 0)} files`)
            const text = prepareText(allFolders);
            writeOutput(text);
        }).catch(e => console.error(e));
});
